// This file is used to define the test library

#ifndef TESTLIB_H
#define TESTLIB_H

// color guards
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

typedef struct test {
    char* description;
    int result;
} test;

// This function is used to run the tests
// it creates a c file, compiles it, runs it and cleans up
void test_runner(test* tests, int num_tests);


#endif
