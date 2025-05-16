// This programm is used to run tests

#include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
#include "testlib.h"

// test functions
// returns 0 if passed, 1 if failed
int test1(void) {
    return 0;
}

int test2(void) {
    return 1;
}

// test runner, takes char* for description and pointer to test functions
void tests(void) {
    test("if pointer is NULL", test1);
    test("if pointer is not null", test2);
}

// This application creates c file that takes test library, 
int main(int argc, char *argv[]) {
    test_runner(tests);
    return 0;
}




