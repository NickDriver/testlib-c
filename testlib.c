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

void testing(test* test) {
    printf(YELLOW"TEST:"RESET" %s", test->description);
    if (test->result != 0) {
        printf(":---:"RED"FAILED"RESET"\n");
    } else {
        printf(":---:"GREEN"PASSED"RESET"\n");
    }
}

void test_runner(test* tests, int num_tests) {
    // run tests
    for (int i = 0; i < num_tests; i++) {
        testing(&tests[i]);
    }
}

