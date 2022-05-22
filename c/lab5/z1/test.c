#include "CUnit/Basic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c"

void run_units()
{
    // dayToString
    CU_ASSERT_STRING_EQUAL(dayToString(MON), "poniedziałek");
    CU_ASSERT_STRING_EQUAL(dayToString(TUE), "wtorek");
    CU_ASSERT_STRING_EQUAL(dayToString(WED), "środa");
    CU_ASSERT_STRING_EQUAL(dayToString(THU), "czwartek");
    CU_ASSERT_STRING_EQUAL(dayToString(FRI), "piątek");
    CU_ASSERT_STRING_EQUAL(dayToString(SAT), "sobota");
    CU_ASSERT_STRING_EQUAL(dayToString(SUN), "niedziela");

    // getEnumNextDay
    CU_ASSERT_EQUAL(getEnumNextDay(MON),TUE);
    CU_ASSERT_EQUAL(getEnumNextDay(TUE),WED);
    CU_ASSERT_EQUAL(getEnumNextDay(WED),THU);
    CU_ASSERT_EQUAL(getEnumNextDay(THU),FRI);
    CU_ASSERT_EQUAL(getEnumNextDay(FRI),SAT);
    CU_ASSERT_EQUAL(getEnumNextDay(SAT),SUN);
    CU_ASSERT_EQUAL(getEnumNextDay(SUN),MON);

    // getEnumPrevDay
    CU_ASSERT_EQUAL(getEnumPrevDay(MON),SUN);
    CU_ASSERT_EQUAL(getEnumPrevDay(TUE),MON);
    CU_ASSERT_EQUAL(getEnumPrevDay(WED),TUE);
    CU_ASSERT_EQUAL(getEnumPrevDay(THU),WED)
    CU_ASSERT_EQUAL(getEnumPrevDay(FRI),THU);
    CU_ASSERT_EQUAL(getEnumPrevDay(SAT),FRI);
    CU_ASSERT_EQUAL(getEnumPrevDay(SUN),SAT);

    // parse
    char *operations[] = {"t+","t-","invalid","d+","d+-","d-","d-","d+"};
    size_t oprLen = sizeof operations/(sizeof(*operations));
    enum Action actions[] = {TIME_LATER,TIME_EARLIER,DAY_LATER,DAY_EARLIER,DAY_EARLIER,DAY_LATER;
    enum Action *test_array = parse(oprLen,operations);
    for(int idx = 0; idx < oprLen; idx++)
        CU_ASSERT_EQUAL(test_array[idx],actions[idx]);
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