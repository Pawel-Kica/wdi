#define globalminDay MON
#define globalmaxDay FRI
#define globalminHour_default 8
#define globalmaxHour_default 20
#define globalminHour_end 9
#define globalmaxHour_end 17

typedef enum days_types {MON=0, TUE, WED, THU, FRI, SAT, SUN, numberOfDays} Day;
typedef enum action_types {DAY_EARLIER = 0, DAY_LATER, TIME_EARLIER, TIME_LATER} Action;
struct Term{
    int hour;
    int minute;
    int duration;
    Day day;
};
typedef struct lesson_type{
    struct Term *term;
    char *name;
}Lesson;

const char days[numberOfDays][20] = {"poniedziałek", "wtorek", "środa", "czwartek", "piątek", "sobota", "niedziela"};
const char* dayToString(Day day){
    return (char*)days[day];
}
Day getEnumNextDay(Day day){
    return day == SUN ? MON : day+1;
}
Day getEnumPrevDay(Day day){
    return day == MON ? SUN : day-1;
}
Action* parse(int arr_size, char *arr[]){
    Action *action_types = malloc(arr_size*sizeof(*arr));
    int counter = 0;

    for(int i = 0; i < arr_size; i++){
        char* value = arr[i];
        if(!strcmp(value,"d-"))
            action_types[counter++] = DAY_EARLIER;
        else if(!strcmp(value,"d+"))
            action_types[counter++] = DAY_LATER;
        else if(!strcmp(value,"t-"))
            action_types[counter++] = TIME_EARLIER;
        else if(!strcmp(value,"t+"))
            action_types[counter++] = TIME_LATER;
    }
    if(arr_size != counter)
        action_types = realloc(action_types, counter*sizeof(*arr));
    return action_types;
}

// TERMS
void Term__init(struct Term *term_obj, int hour, int minute, int duration,Day day){
    term_obj->minute = minute;
    term_obj->hour = hour;
    term_obj->duration = duration;
    term_obj->day = day;
}
struct Term* Term__create(int hour,int minute, int duration,Day day){
    struct Term *term_obj = malloc(sizeof(struct Term));
    Term__init(term_obj,hour,minute,duration,day);
    return term_obj;
}
char *Term__toString(struct Term *term_obj){
    char *result = malloc(strlen((dayToString(term_obj->day))+1)*sizeof(*result));

    strcpy(result,dayToString(term_obj->day));
    char counter = strlen(result);

    printf("\n RESULT: %s \n",result);
    // int hour = term_obj->hour;
    // int minute = term_obj->minute;
    // int duration = term_obj->duration;

    // if(hour < 10){
    //     result[counter++] = '0';
    //     result[counter++] = hour;
    // }
    // else{
    //     result[counter++] = hour/10;
    //     result[counter++] = hour%10;
    // }
    // printf("%i value \n",result[0]);
    // printf("%i value \n",result[1]);
    // printf("%s val\n",result);

    return result;
}
// LESSONS
void Lesson__init(Lesson *lesson_obj, int hour, int minute, int duration,Day day,char *name){
    lesson_obj->name = malloc(strlen(name) * sizeof(*name));
    strcpy(lesson_obj->name,name);
    Term__init(lesson_obj->term,hour,minute,duration,day);
}
Lesson *create_lesson(int hour, int minute, int duration, Day day, char *name){
    Lesson *lesson_obj = malloc(sizeof(lesson_obj));
    lesson_obj->term = Term__create(hour,minute,duration,day);
    lesson_obj->name = malloc(strlen(name) * sizeof(*name));
    strcpy(lesson_obj->name,name);
    return lesson_obj;
}
bool canBeMoved(Lesson* lesson_obj){
    int day = lesson_obj->term->day;

    int lesson_duration = lesson_obj->term->duration;
    int lesson_minutes = lesson_obj->term->minute;

    int endOfLesson_hour = lesson_obj->term->hour + (lesson_duration+lesson_minutes)/60;
    int endOfLesson_minutes = (lesson_minutes + lesson_duration)%60;

    if(day>=globalminDay && day<globalmaxDay){
        if(endOfLesson_hour<globalminHour_default) return false;
        if(endOfLesson_hour>globalmaxHour_default) return false;

        if(endOfLesson_hour==globalmaxHour_default && endOfLesson_minutes>0) return false;

        return true;
    }
    if(day!=globalmaxDay) return false;
    if(endOfLesson_hour<globalminHour_end) return false;
    if(endOfLesson_hour>globalmaxHour_end) return false;
    if(endOfLesson_hour==globalmaxHour_end && endOfLesson_minutes>0)return false;
    return true;
}
void Lesson__earlierDay(Lesson* lesson_obj){
    lesson_obj->term->day = getEnumPrevDay(lesson_obj->term->day);
    if(!canBeMoved){
        printf("Zajęcia \"%s\" nie mogą być przesunięte na termin \"%s\"\n",lesson_obj->name,Term__toString(lesson_obj->term));
        lesson_obj->term->day = getEnumNextDay(lesson_obj->term->day);   
    }
}
void Lesson__laterDay(Lesson* lesson_obj){
    lesson_obj->term->day = getEnumNextDay(lesson_obj->term->day);
    if(!canBeMoved){
        printf("Zajęcia \"%s\" nie mogą być przesunięte na termin \"%s\"\n",lesson_obj->name,Term__toString(lesson_obj->term));
        lesson_obj->term->day = getEnumPrevDay(lesson_obj->term->day);   
    }
}
void Lesson__earlierTime(Lesson* lesson_obj){
    int hour_start = lesson_obj->term->duration/60;
    int minute_start = lesson_obj->term->duration%60;
    lesson_obj->term->hour = lesson_obj->term->hour - hour_start;
    lesson_obj->term->minute = lesson_obj->term->minute - minute_start;

    if(!canBeMoved){
        printf("Zajęcia \"%s\" nie mogą być przesunięte na termin \"%s\"\n",lesson_obj->name,Term__toString(lesson_obj->term));
        lesson_obj->term->hour = lesson_obj->term->hour + hour_start;
        lesson_obj->term->minute = lesson_obj->term->minute + minute_start;
    }
}
void Lesson__laterTime(Lesson* lesson_obj){
    int hour_start = lesson_obj->term->duration/60;
    int minute_start = lesson_obj->term->duration%60;
    lesson_obj->term->hour = lesson_obj->term->hour + hour_start;
    lesson_obj->term->minute = lesson_obj->term->minute + minute_start;
    if(!canBeMoved){
        printf("Zajęcia \"%s\" nie mogą być przesunięte na termin \"%s\"\n",lesson_obj->name,Term__toString(lesson_obj->term));
        lesson_obj->term->hour = lesson_obj->term->hour - hour_start;
        lesson_obj->term->minute = lesson_obj->term->minute - minute_start;
    }
}
char* Lesson__toString(Lesson* lesson_obj){

}