#include "compute.h"

int main() {

    //Results
    double result_magic[20];
    int result_count;
    double result_median;

    // Test cases
    int test1[9] = {5, 6, 6, 6, 6, 6, 6, 6, 7};
    int test2[10] = {0, 10, 11, 12, 12, 13 , 13, 14, 14, 15};
    int test3[11] = {0, 1, 50, 51, 52, 53, 54, 55, 57, 100, 110};
    int test4[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int num = 9;
    result_median = findMedian(test1, num);
    magic(test1, num, result_magic, result_count);
    printStats(test1, num, result_median, result_magic, result_count);

    num++;
    result_median = findMedian(test2, num);
    magic(test2, num, result_magic, result_count);
    printStats(test2, num, result_median, result_magic, result_count);

    num++;
    result_median = findMedian(test3, num);
    magic(test3, num, result_magic, result_count);
    printStats(test3, num, result_median, result_magic, result_count);

    num++;
    result_median = findMedian(test4, num);
    magic(test4, num, result_magic, result_count);
    printStats(test4, num, result_median, result_magic, result_count);
}

