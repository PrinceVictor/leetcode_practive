#include <iostream>
#include <random>
#include <vector>
#include <ctime>

void swap(int a, int b){

    int temp = a;
    a = b;
    b = temp;
    printf("in swaping: a %d b %d\n", a, b);
}

void create_random_vector(std::vector<int>& output_random_vector,
                          const int& begin, const int& end, const bool time_used){

    std::time_t current_time;
    std::time(&current_time);

    int total_size = end-begin;

    std::default_random_engine randomEngine;

    if(time_used) randomEngine.seed(current_time);

    std::uniform_int_distribution<int> random_vector(-10, 10);
    output_random_vector.resize(total_size);

    printf("total:%d random number\n", total_size);
    for(int i=0; i<total_size; i++){

        output_random_vector[i] = random_vector(randomEngine);
        printf("%d\t", i, output_random_vector[i]);
    }


}

int main(int argc, char** agrv){

    std::vector<int> random_vector;

    create_random_vector(random_vector, -20, 20, true);

    return 0;
}