#include "CUnit/Basic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stringToHex.c"

void run_units()
{
    char* input;

    input = stringToHex("A");
	CU_ASSERT_STRING_EQUAL(input, "41");
	
	input = stringToHex("B");
	CU_ASSERT_STRING_EQUAL(input, "42");

	input = stringToHex("(");
	CU_ASSERT_STRING_EQUAL(input, "28");


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

    if (NULL == CU_add_test(pSuite, "string to hex tests", run_units))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();
    return CU_get_error();
}