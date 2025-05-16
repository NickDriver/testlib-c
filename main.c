// This programm is used to run tests
#include <stdio.h>
#include "testlib.h"

test test1 = {
    .description = "if pointer is NULL",
    .result = 5-5
};

test test2 = {
    .description = "if pointer is not null",
    .result = 5-4
};

// This application creates c file that takes test library, 
int main(int argc, char *argv[]) {
    test tests[] = {test1, test2};
    test_runner(tests, 2);
    return 0;
}
