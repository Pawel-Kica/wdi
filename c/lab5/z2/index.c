#include "CUnit/Basic.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "functions.c"

void run_units(){
    int val1 = 12;
    int val2 = 15;
    int val3 = 40;

    // Term__init
    struct Term *test_obj_Term__init = malloc(sizeof(struct Term));
    Term__init(test_obj_Term__init,val1,val2,val3);
    CU_ASSERT_EQUAL(test_obj_Term__init->hour,val1);
    CU_ASSERT_EQUAL(test_obj_Term__init->minute,val2);
    CU_ASSERT_EQUAL(test_obj_Term__init->duration,val3);


    // Term__create
    struct Term *test_obj_1_Term__create = Term__create(val1,val2,val3);
    CU_ASSERT_EQUAL(test_obj_1_Term__create->hour,val1);
    CU_ASSERT_EQUAL(test_obj_1_Term__create->minute,val2);
    CU_ASSERT_EQUAL(test_obj_1_Term__create->duration,val3);

    struct Term *test_obj_2_Term__create = Term__create(val3,val2,val1);
    CU_ASSERT_EQUAL(test_obj_2_Term__create->hour,val3);
    CU_ASSERT_EQUAL(test_obj_2_Term__create->minute,val2);
    CU_ASSERT_EQUAL(test_obj_2_Term__create->duration,val1);
    
    struct Term *test_obj_3_Term__create = Term__create(val2,val3,val1);
    CU_ASSERT_EQUAL(test_obj_3_Term__create->hour,val2);
    CU_ASSERT_EQUAL(test_obj_3_Term__create->minute,val3);
    CU_ASSERT_EQUAL(test_obj_3_Term__create->duration,val1);

    // Term__destroy
    Term__destroy(test_obj_3_Term__create);
    CU_ASSERT_EQUAL(test_obj_3_Term__create->hour,NULL);
    CU_ASSERT_EQUAL(test_obj_3_Term__create->minute,NULL);
    // CU_ASSERT_EQUAL(test_obj_3_Term__create->duration,NULL);


    // Term__toString
    struct Term *test_obj_1_Term__toString = Term__create(12,15,40);
    CU_ASSERT_EQUAL(Term__toString(test_obj_1_Term__toString),"12");
    
    // Term_earlierThan
    struct Term *test_obj_1_Term__earlierThan = Term__create(12,15,40);
    struct Term *test_obj_2_Term__earlierThan = Term__create(12,20,40);
    struct Term *test_obj_3_Term__earlierThan = Term__create(13,15,40);
    struct Term *test_obj_4_Term__earlierThan = Term__create(13,15,40);
    CU_ASSERT_TRUE(Term__earlierThan(test_obj_1_Term__earlierThan,test_obj_2_Term__earlierThan))
    CU_ASSERT_TRUE(Term__earlierThan(test_obj_2_Term__earlierThan,test_obj_3_Term__earlierThan))

    // Term_laterThan
    CU_ASSERT_TRUE(Term__laterThan(test_obj_2_Term__earlierThan,test_obj_1_Term__earlierThan))
    CU_ASSERT_TRUE(Term__laterThan(test_obj_3_Term__earlierThan,test_obj_2_Term__earlierThan))

    // Term_equals
    CU_ASSERT_TRUE(Term__equals(test_obj_3_Term__earlierThan,test_obj_4_Term__earlierThan))

    // Term_endTerm

    struct Term *test_obj_1_Term__endTerm = Term__create(9,45,90);
    struct Term *test_obj_2_Term__endTerm = Term__create(10,15,90);
    struct Term *result_endTerm = Term__endTerm(test_obj_1_Term__endTerm,test_obj_2_Term__endTerm);

    CU_ASSERT_EQUAL(result_endTerm->hour,test_obj_1_Term__endTerm->hour);
    CU_ASSERT_EQUAL(result_endTerm->minute,test_obj_1_Term__endTerm->minute);
    CU_ASSERT_EQUAL(result_endTerm->duration,30);
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