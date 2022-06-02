#define globalminDay MON
#define globalmaxDay FRI
#define globalminHour_default 8
#define globalmaxHour_default 20
#define globalminHour_end 8
#define globalmaxHour_end 17

typedef enum days_types
{
    MON = 0,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN,
    numberOfDays
} Day;
typedef enum action_types
{
    DAY_EARLIER = 0,
    DAY_LATER,
    TIME_EARLIER,
    TIME_LATER
} Action;

struct Term
{
    int hour;
    int minute;
    int duration;
    Day day;
};
typedef struct lesson_type
{
    struct Term *term;
    char *name;
} Lesson;

const char days[numberOfDays][20] = {"poniedziałek", "wtorek", "środa", "czwartek", "piątek", "sobota", "niedziela"};
const char *dayToString(Day day)
{
    return (char *)days[day];
}
Day getEnumNextDay(Day day)
{
    return day == SUN ? MON : day + 1;
}
Day getEnumPrevDay(Day day)
{
    return day == MON ? SUN : day - 1;
}
Action *parse(int arr_size, char *array[])
{
    Action *action_types = malloc(arr_size * sizeof(*array));
    int counter = 0;

    for (int i = 0; i < arr_size; i++)
    {
        char *value = array[i];
        if (!strcmp(value, "d-"))
            action_types[counter++] = DAY_EARLIER;
        else if (!strcmp(value, "d+"))
            action_types[counter++] = DAY_LATER;
        else if (!strcmp(value, "t-"))
            action_types[counter++] = TIME_EARLIER;
        else if (!strcmp(value, "t+"))
            action_types[counter++] = TIME_LATER;
    }
    if (arr_size != counter)
        action_types = realloc(action_types, counter * sizeof(*array));
    return action_types;
}

// TERMS
void Term__init(struct Term *term_obj, int hour, int minute, int duration, Day day)
{
    term_obj->minute = minute;
    term_obj->hour = hour;
    term_obj->duration = duration;
    term_obj->day = day;
}
struct Term *Term__create(int hour, int minute, int duration, Day day)
{
    struct Term *term_obj = malloc(sizeof(struct Term));
    Term__init(term_obj, hour, minute, duration, day);
    return term_obj;
}
char *Term__toString(struct Term *term_obj)
{
    char *result = malloc((strlen(dayToString(term_obj->day)) + 20) * sizeof(*result));
    strcpy(result, dayToString(term_obj->day));
    char counter = strlen(result);
    int hour = term_obj->hour;
    int minute = term_obj->minute;
    int duration = term_obj->duration;
    result[counter++] = ' ';
    if (hour > 9)
    {
        result[counter++] = '0' + term_obj->hour / 10;
        result[counter++] = '0' + term_obj->hour % 10;
    }
    else
    {
        result[counter++] = '0';
        result[counter++] = '0' + hour;
    }
    result[counter++] = ':';
    result[counter++] = '0' + minute / 10;
    result[counter++] = '0' + minute % 10;
    result[counter++] = ' ';
    result[counter++] = '[';
    result[counter++] = '0' + duration / 10;
    result[counter++] = '0' + duration % 10;
    result[counter++] = ']';
    return result;
}

// LESSONS
void Lesson__init(Lesson *lesson_obj, int hour, int minute, int duration, Day day, char *name)
{
    lesson_obj->name = malloc(strlen(name) * sizeof(*name));
    strcpy(lesson_obj->name, name);
    Term__init(lesson_obj->term, hour, minute, duration, day);
}
Lesson *create_lesson(int hour, int minute, int duration, Day day, char *name)
{
    Lesson *lesson_obj = malloc(sizeof(lesson_obj));
    lesson_obj->term = Term__create(hour, minute, duration, day);
    lesson_obj->name = malloc(strlen(name) * sizeof(*name));
    strcpy(lesson_obj->name, name);
    return lesson_obj;
}

bool canBeMoved(Lesson *lesson_obj)
{
    int day = lesson_obj->term->day;

    int startOfLesson_hour = lesson_obj->term->hour;
    int lesson_minutes = lesson_obj->term->minute;
    int lesson_duration = lesson_obj->term->duration;

    int endOfLesson_hour = startOfLesson_hour + (lesson_duration + lesson_minutes) / 60;
    int endOfLesson_minutes = (lesson_minutes + lesson_duration) % 60;

    if (day >= globalminDay && day < globalmaxDay)
    {
        if (startOfLesson_hour < globalminHour_default)
            return false;
        if (endOfLesson_hour > globalmaxHour_default)
            return false;

        if (endOfLesson_hour == globalmaxHour_default && endOfLesson_minutes > 0)
            return false;

        return true;
    }
    if (day != globalmaxDay)
        return false;
    if (endOfLesson_hour < globalminHour_end)
        return false;
    if (endOfLesson_hour > globalmaxHour_end)
        return false;
    if (endOfLesson_hour == globalmaxHour_end && endOfLesson_minutes > 0)
    {
        return false;
    }

    return true;
}
void Lesson__earlierDay(Lesson *lesson_obj)
{
    lesson_obj->term->day = getEnumPrevDay(lesson_obj->term->day);
    if (!canBeMoved(lesson_obj))
    {
        printf("Zajęcia \"%s\" nie mogą być przesunięte na termin \"%s\"\n", lesson_obj->name, Term__toString(lesson_obj->term));
        lesson_obj->term->day = getEnumNextDay(lesson_obj->term->day);
    }
}
void Lesson__laterDay(Lesson *lesson_obj)
{
    lesson_obj->term->day = getEnumNextDay(lesson_obj->term->day);
    if (!canBeMoved(lesson_obj))
    {
        printf("Zajęcia \"%s\" nie mogą być przesunięte na termin \"%s\"\n", lesson_obj->name, Term__toString(lesson_obj->term));
        lesson_obj->term->day = getEnumPrevDay(lesson_obj->term->day);
    }
}
void Lesson__earlierTime(Lesson *lesson_obj)
{
    int hour = lesson_obj->term->hour;
    int minute = lesson_obj->term->minute;
    int duration = lesson_obj->term->duration;

    int hour_start = duration / 60;
    int minute_start = duration % 60;

    if (minute - minute_start < 0)
    {
        lesson_obj->term->hour = hour - hour_start - 1;
        lesson_obj->term->minute = minute + minute_start;
    }
    else
    {
        lesson_obj->term->hour = hour - hour_start;
        lesson_obj->term->minute = minute - minute_start;
    }
    if (!canBeMoved(lesson_obj))
    {
        printf("Zajęcia \"%s\" nie mogą być przesunięte na termin \"%s\"\n", lesson_obj->name, Term__toString(lesson_obj->term));

        lesson_obj->term->hour = hour;
        lesson_obj->term->minute = minute;
        // if (minute - minute_start < 0)
        // {
        // }
        // else
        // {
        //     lesson_obj->term->hour = hour + hour_start;
        //     lesson_obj->term->minute = minute + minute_start;
        // }
    }
}
void Lesson__laterTime(Lesson *lesson_obj)
{
    int hour = lesson_obj->term->hour;
    int minute = lesson_obj->term->minute;
    int duration = lesson_obj->term->duration;

    int hour_start = duration / 60;
    int minute_start = duration % 60;

    if (minute + minute_start < 60)
    {
        lesson_obj->term->hour = hour + hour_start;
        lesson_obj->term->minute = minute + minute_start;
    }
    else
    {
        lesson_obj->term->hour = hour + hour_start + 1;
        lesson_obj->term->minute = abs(minute - minute_start);
    }

    if (!canBeMoved(lesson_obj))
    {
        printf("Zajęcia \"%s\" nie mogą być przesunięte na termin \"%s\"\n", lesson_obj->name, Term__toString(lesson_obj->term));
        lesson_obj->term->hour = hour;
        lesson_obj->term->minute = minute;
    }
}
char *Lesson__toString(Lesson *lesson_obj)
{
    char *result = malloc(50 * sizeof(*result));
    strcpy(result, lesson_obj->name);
    strcat(result, ", ");
    strcat(result, Term__toString(lesson_obj->term));
    return result;
}