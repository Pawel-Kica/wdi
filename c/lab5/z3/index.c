#include "CUnit/Basic.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdbool.h>
#define globalminDay MON
#define globalmaxDay FRI
#define globalminHour_default 8
#define globalmaxHour_default 20
#define globalminHour_end 9
#define globalmaxHour_end 17

typedef enum days_types {MON=0, TUE, WED, THU, FRI, SAT, SUN, numberOfDays} Day;

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

// struct LimitsConfigType{
//     Day minDay;
//     Day maxDay;
//     int minHour_default;
//     int maxHour_default;
//     int minHour_end;
//     int maxHour_end;
// };
// struct LimitsConfigType *LimitsConfig = malloc(sizeof(struct LimitsConfigType));
// LimitsConfig->minDay = MON;
// LimitsConfig->maxDay = FRI;
// LimitsConfig->minHour_default=8;
// LimitsConfig->maxHour_default=20;
// LimitsConfig->minHour_end=9;
// LimitsConfig->minHour_end=17;

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
void Term__destroy(struct Term *term_obj){
    free(term_obj);
}
char *Term__toString(struct Term *term_obj){
    char *result = malloc(20*sizeof(*result));

    int counter = 0;
    int hour = term_obj->hour;
    int minute = term_obj->minute;
    int duration = term_obj->duration;

    if(hour < 10){
        result[counter++] = '0';
        result[counter++] = hour;
    }
    else{
        result[counter++] = hour/10;
        result[counter++] = hour%10;
    }
    // printf("%i value \n",result[0]);
    // printf("%i value \n",result[1]);
    // printf("%s val\n",result);

    return result;
}
bool Term__earlierThan(struct Term *term1,struct Term *term2){
    if(term1->hour==term2->hour){
        if(term1->minute<term2->minute) return true;
    }
    return term1->hour<term2->hour;
}
bool Term__laterThan(struct Term *term1,struct Term *term2){
    return !Term__earlierThan(term1,term2);
}
bool Term__equals(struct Term *term1,struct Term *term2){
    return (term1->hour==term2->hour && term1->minute==term2->minute);
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
//

bool canBeMoved(Lesson* lesson_obj){
    int day = lesson_obj->term->day;

    int lesson_duration = lesson_obj->term->duration;
    int lesson_minutes = lesson_obj->term->minute;

    int endOfLesson_hour = lesson_obj->term->hour + (lesson_duration+lesson_minutes)/60;
    int endOfLesson_minutes = (lesson_minutes + lesson_duration)%60;

    if(day>=globalminDay && day<globalmaxDay){
        if(endOfLesson_hour<globalminHour_default) return false;
        if(endOfLesson_hour>globalmaxHour_default) return false;

        if(endOfLesson_hour==globalminHour_default) return true;
        if(endOfLesson_hour==globalmaxHour_default && endOfLesson_minutes==0) return true;

        printf("tudijsakjdsjkadsjkl");
    }
    if(day!=globalmaxDay) return false;

    if(endOfLesson_hour<globalminHour_end) return false;
    if(endOfLesson_hour>globalmaxHour_end) return false;

    if(endOfLesson_hour==globalminHour_end) return true;
    if(endOfLesson_hour==globalmaxHour_end && endOfLesson_minutes==0) return true;
}

void Lesson__earlierDay(Lesson* lesson_obj){
    lesson_obj->term->day = getEnumPrevDay(lesson_obj->term->day);
    lesson_obj->term->day = getEnumNextDay(lesson_obj->term->day);
    printf("Zajęcia \"%s\" nie mogą być przesunięte na termin \"%s\"\n",lesson_obj->name,Term__toString(lesson_obj->term));
}
void Lesson__laterDay(Lesson* lesson_obj){

}
void Lesson__earlierTime(Lesson* lesson_obj){

}
void Lesson__laterTime(Lesson* lesson_obj){

}
char* Lesson__toString(Lesson* lesson_obj){

}

void run_units(){
    int val1 = 12;
    int val2 = 15;
    int val3 = 40;
    char val_name[50] = "podstawy programowania";
    
    // Lessons create and init
    Lesson *lesson1 = malloc(sizeof(Lesson));
    struct Term *term1 = malloc(sizeof(struct Term));

    lesson1->term = term1;
    Lesson__init(lesson1,val1,val2,val3,MON,val_name);
    CU_ASSERT_EQUAL(lesson1->term->hour,val1);
    CU_ASSERT_EQUAL(lesson1->term->minute,val2);
    CU_ASSERT_EQUAL(lesson1->term->duration,val3);
    CU_ASSERT_EQUAL(lesson1->term->day,MON);
    CU_ASSERT_STRING_EQUAL(lesson1->name,val_name);
}

int main()
{
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
        
    pSuite = CU_add_suite("testing_test_library", 0, 0);

    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "main units", run_units))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();
    return CU_get_error();
}