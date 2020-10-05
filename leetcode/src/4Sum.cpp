//
// Created by victor on 2020/10/5.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include "4Sum.h"

std::vector<int> nums_(){
    return {1, 0, -1, 0, -2, 2};
}

int target_(){
    return 0;
}

std::vector<std::vector<int>> fourSum(std::vector<int> nums, int target){

    std::vector<std::vector<int>> all_solutions;

    std::sort(nums.begin(), nums.end(), std::less<int>());

//    for(auto it: nums){
//        printf("%d\t", it);
//    }
//    printf("\n");

    int total_size = nums.size();
    int left_index, right_index;
    for(int i=0; i<total_size-3; i++){
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for(int j=i+1; j<total_size-2; j++){
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            left_index=j+1; right_index=total_size-1;

            while (left_index<right_index){
                int sum = nums[i]+nums[j]+nums[left_index]+nums[right_index];
                if(sum == target){

                    all_solutions.push_back({nums[i],
                                             nums[j],
                                             nums[left_index],
                                             nums[right_index]});
                    while (left_index < right_index && nums[left_index] == nums[left_index + 1]) {
                        left_index++;
                    }
                    left_index++;
                    while (left_index < right_index && nums[right_index] == nums[right_index - 1]) {
                        right_index--;
                    }
                    right_index--;
                }
                else if(sum < target){
                    left_index++;
                }
                else{
                    right_index--;
                }
            }
        }
    }
//    printf("\n");
//
//    for(auto it: all_solutions){
//        for(auto its:it){
//            printf("%d\t", its);
//        }
//        printf("\n");
//    }

    return all_solutions;
}

