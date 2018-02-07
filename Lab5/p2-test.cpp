#include "mode.h"

int main() {

    const int NUM_TERMS = 10;

    // Results
    int result[NUM_TERMS];
    int result_frequency, result_count;

    // Test cases
    int test1[NUM_TERMS] = {2, 3, 4, 4, 3 ,1, 2, 1, 2, 3};
    int test2[NUM_TERMS] = {9, 8, 7, 6, 5 ,4, 3, 2, 1, 0};
    int test3[NUM_TERMS] = {1, 3, 4, 9, 7 ,8, 12, 13, 2, 3};
    int test4[NUM_TERMS] = {2, 3, 4, 4, 5 ,1, 2, 1, 5, 3};

    findModes(test1, NUM_TERMS, result_frequency, result, result_count);
    printModes(test1, NUM_TERMS, result_frequency, result, result_count);

    findModes(test2, NUM_TERMS, result_frequency, result, result_count);
    printModes(test2, NUM_TERMS, result_frequency, result, result_count);

    findModes(test3, NUM_TERMS, result_frequency, result, result_count);
    printModes(test3, NUM_TERMS, result_frequency, result, result_count);

    findModes(test4, NUM_TERMS, result_frequency, result, result_count);
    printModes(test4, NUM_TERMS, result_frequency, result, result_count);

}
