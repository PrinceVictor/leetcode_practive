//
// Created by victor on 2020/9/27.
//
#include <climits>

#include "maxsum_of_subseq.h"

/**
 * @brief get max sum of sub sequence with O(N^3)
 * @param random_input: random vector input
 * @return max sum of sub sequence
 */
_maxsum_struct maxsum_of_subseq1(const std::vector<int>& random_input){

    _maxsum_struct maxsumStruct{INT_MIN, 0, 0};

    int i,j,k;
    for( i=0; i<random_input.size(); i++){
        for( j=i; j<random_input.size(); j++){

            int this_sum = 0;
            for( k=i; k<=j; k++){
                this_sum += random_input[k];
            }

            if(this_sum > maxsumStruct.maxSum){
                maxsumStruct.maxSum = this_sum;
                maxsumStruct.begin = i;
                maxsumStruct.end = j;
            }
        }
    }

    return maxsumStruct;
}

/**
 * @brief get max sum of sub sequence with O(N^2)
 * @param random_input: random vector input
 * @return max sum of sub sequence
 */
_maxsum_struct maxsum_of_subseq2(const std::vector<int>& random_input){

    _maxsum_struct maxsumStruct{INT_MIN, 0, 0};

    int i,j;
    for( i=0; i<random_input.size(); i++){

        int this_sum = 0;
        for( j=i; j<random_input.size(); j++){

            this_sum += random_input[j];

            if(this_sum > maxsumStruct.maxSum){
                maxsumStruct.maxSum = this_sum;
                maxsumStruct.begin = i;
                maxsumStruct.end = j;
            }
        }
    }

    return maxsumStruct;
}

/**
 * @brief get max sum of sub sequence with O(N)
 * @param random_input: random vector input
 * @return max sum of sub sequence
 */
_maxsum_struct maxsum_of_subseq3(const std::vector<int> &random_input) {

    _maxsum_struct maxsumStruct{INT_MIN, 0, 0};

    int i, this_sum = 0, temp_begin=0;
    for( i=0; i<random_input.size(); i++){

        this_sum += random_input[i];

        if(this_sum < 0){
            this_sum = 0;
            temp_begin = i+1;
        }

        if(this_sum > maxsumStruct.maxSum){
            maxsumStruct.maxSum = this_sum;
            maxsumStruct.begin = temp_begin;
            maxsumStruct.end = i;
        }
    }

    return maxsumStruct;
}
