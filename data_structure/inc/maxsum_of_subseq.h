//
// Created by victor on 2020/9/27.
//

#ifndef DATA_STRUCTURE_MAXSUM_OF_SUBSEQ_H
#define DATA_STRUCTURE_MAXSUM_OF_SUBSEQ_H

#include <vector>


typedef struct{

    int maxSum;
    int begin;
    int end;

}_maxsum_struct;

_maxsum_struct maxsum_of_subseq1(const std::vector<int>& random_input);
_maxsum_struct maxsum_of_subseq2(const std::vector<int>& random_input);
_maxsum_struct maxsum_of_subseq3(const std::vector<int>& random_input);

#endif //DATA_STRUCTURE_MAXSUM_OF_SUBSEQ_H
