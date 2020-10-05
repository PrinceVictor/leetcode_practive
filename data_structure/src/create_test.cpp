//
// Created by victor on 2020/9/26.
//
#include <chrono>
#include "create_test.h"
#include "maxsum_of_subseq.h"

void create_random_vector(std::vector<int>& output_random_vector,
                          const int& begin, const int& end, const bool time_used){

    std::time_t current_time;
    std::time(&current_time);

    int total_size = end-begin;

    std::default_random_engine randomEngine{};

    if(time_used) randomEngine.seed(current_time);

    std::uniform_int_distribution<int> random_vector(begin, end);
    output_random_vector.resize(total_size);

    printf("total:%d random number\n", total_size);
    for(int i=0; i<total_size; i++){

        if(i%5==0 && i!=0){
            printf("\n");
        }

        output_random_vector[i] = random_vector(randomEngine);
        printf("%d\t", output_random_vector[i]);
    }
    printf("\n");
}

void runEvaluation_maxsumOfsubseq(){

    std::vector<int> random_vector;
    _maxsum_struct maxsumStruct;

    create_random_vector(random_vector, -100, 100, true);

    std::chrono::steady_clock::time_point time_point =
            std::chrono::steady_clock::now();

    maxsumStruct = maxsum_of_subseq1(random_vector);

    printf("max sum: %d begin: %d end: %d\n", maxsumStruct.maxSum,
                                                      maxsumStruct.begin,
                                                      maxsumStruct.end);

    double time_cost1 = std::chrono::duration_cast<std::chrono::microseconds>
            (std::chrono::steady_clock::now() - time_point).count();
    printf("algorithm1 took %.4f ms\n", time_cost1/1000);

    maxsumStruct = maxsum_of_subseq2(random_vector);

    printf("max sum: %d begin: %d end: %d\n", maxsumStruct.maxSum,
                                                      maxsumStruct.begin,
                                                      maxsumStruct.end);

    double time_cost2 = std::chrono::duration_cast<std::chrono::microseconds>
            (std::chrono::steady_clock::now() - time_point).count();
    printf("algorithm2 took %.4f ms\n", (time_cost2-time_cost1)/1000);

    maxsumStruct = maxsum_of_subseq3(random_vector);

    printf("max sum: %d begin: %d end: %d\n", maxsumStruct.maxSum,
           maxsumStruct.begin,
           maxsumStruct.end);

    double time_cost3 = std::chrono::duration_cast<std::chrono::microseconds>
            (std::chrono::steady_clock::now() - time_point).count();
    printf("algorithm3 took %.4f ms\n", (time_cost3-time_cost2)/1000);

}
