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

void test(char* description, int (*test_function)(void)) {
    printf(YELLOW"TEST:"RESET" %s", description);
    if (test_function() != 0) {
        printf(":---:"RED"FAILED"RESET"\n");
    } else {
        printf(":---:"GREEN"PASSED"RESET"\n");
    }
}

void test_runner(void (*tests)(void)) {
    // run tests
    tests();
}

