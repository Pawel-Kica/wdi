#include "CUnit/Basic.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdbool.h>
#include "z3functions.c"

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

    CU_ASSERT_STRING_EQUAL(Term__toString(lesson1->term),dayToString(lesson1->term->day));

    Lesson *lesson2 = create_lesson(14,20,90,SAT,"Algorytmy 1");
    CU_ASSERT_EQUAL(lesson2->term->hour,14);
    CU_ASSERT_EQUAL(lesson2->term->minute,20);
    CU_ASSERT_EQUAL(lesson2->term->duration,90);
    CU_ASSERT_EQUAL(lesson2->term->day,SAT);
    CU_ASSERT_STRING_EQUAL(lesson2->name,"Algorytmy 1");

    // can be moved
    Lesson *lesson3 = create_lesson(16,50,10,FRI,"Algorytmy 2");
    CU_ASSERT_TRUE(canBeMoved(lesson1));
    CU_ASSERT_TRUE(!canBeMoved(lesson2));
    CU_ASSERT_TRUE(canBeMoved(lesson3));
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