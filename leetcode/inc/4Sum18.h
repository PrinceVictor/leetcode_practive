//
// Created by victor on 2020/10/5.
//

#ifndef LEETCODE_4SUM_H
#define LEETCODE_4SUM_H

#include <iostream>
#include <vector>
#include <algorithm>

namespace FourSum {

std::vector<int> nums_();
int target_();

std::vector<std::vector<int>> fourSum(std::vector<int> nums, int target);
std::vector<std::vector<int>> recurseFourSum(std::vector<int> nums, int target);

}

#endif //LEETCODE_4SUM_H
