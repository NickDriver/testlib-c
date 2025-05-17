// This programm is used to run tests
#include <stdio.h>
#include "testlib.h"

test_t test1 = {
    .description = "if pointer is NULL",
    .result = 5-5
};

test_t test2 = {
    .description = "if pointer is not null",
    .result = 5-4
};

int main(int argc, char *argv[]) {
    test_t tests[] = {test1, test2};
    test_runner(tests, 2);
    return 0;
}

