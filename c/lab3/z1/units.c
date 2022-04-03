#include "CUnit/Basic.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "encryptCaeser.c"

void run_units()
{
    char msg[100];

    strcpy(msg, "to be or not to be");
    encryptCaeser(msg);
    CU_ASSERT_STRING_EQUAL(msg, "vq dg qt pqv vq dg");

    strcpy(msg, "ala ma kota");
    encryptCaeser(msg);
    CU_ASSERT_STRING_EQUAL(msg, "dod pd nrwd");

    strcpy(msg, "abcdefghijklmnopqrstuvwxyz");
    encryptCaeser(msg);
    CU_ASSERT_STRING_EQUAL(msg, "abcdefghijklmnopqrstuvwxyz");

    strcpy(msg, " a b c d e f g h i j k l m n o p q r s t u v w x y z");
    encryptCaeser(msg);
    CU_ASSERT_STRING_EQUAL(msg, " b c d e f g h i j k l m n o p q r s t u v w x y z a");
}

int main()
{
    CU_pSuite pSuite = NULL;

    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add a suite to the registry
    pSuite = CU_add_suite("testing_test_library", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "encrypt caeser tests", run_units))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
    // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
    CU_basic_set_mode(CU_BRM_VERBOSE);

    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}