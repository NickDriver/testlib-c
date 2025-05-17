/*
 * Static library: testlib
 * Location: /usr/local/lib
 * This is a static library for testing purposes
 */

#include <stdio.h>
#include <stdlib.h>
#include "testlib.h"


int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

void testing(test_t* test) {
    printf(YELLOW"TEST:"RESET" %s", test->description);
    if (test->result != 0) {
        printf(":---:"RED"FAILED"RESET"\n");
    } else {
        printf(":---:"GREEN"PASSED"RESET"\n");
    }
}

void test_runner(test_t* tests, int num_tests) {
    // run tests
    for (int i = 0; i < num_tests; i++) {
        testing(&tests[i]);
    }
}

// Push test
int push_test(test_list_t* test_list, test_t *test_to_add) {
    if (test_list == NULL) {exit(1);}
    if (test_to_add == NULL) {exit(1);}

    if (test_list->tests == NULL) {
        test_list->tests = (test_t*)malloc(sizeof(test_t));
        if (test_list->tests == NULL) {exit(1);}
        test_list->tests[test_list->num_tests] = *test_to_add;
        test_list->num_tests = 0;
    }

    test_list->tests = (test_t*)realloc(test_list->tests, sizeof(test_t) * (test_list->num_tests + 1));
    if (test_list->tests == NULL) {exit(1);}
    test_list->tests[test_list->num_tests] = *test_to_add;
    test_list->num_tests++;

    return 0;
}