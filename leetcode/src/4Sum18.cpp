//
// Created by victor on 2020/10/5.
//
#include "4Sum18.h"

namespace FourSum {

std::vector<int> nums_(){
    return {1, 0, -1, 0, -2, 2};
//    return {0, 0, 0, 0};
}

int target_(){
    return 0;
}

std::vector<std::vector<int>> kSum(std::vector<int>& nums, int target, int k, int start){

    std::vector<std::vector<int>> res;
    if(start == nums.size() || nums[start]*k>target || nums.back()*k<target)
        return res;

    if(k==2){
        int low=start, high=nums.size()-1;
        while(low < high){
            if(target==nums[low]+nums[high]){

                res.push_back({nums[low], nums[high]});
                while (low < high && nums[low] == nums[low + 1]) low++;
                low++;
                while (low < high && nums[high] == nums[high - 1]) high--;
                high--;
            }
            else target < nums[low]+nums[high] ? high-- : low++;
        }
    }
    else{

        for(int i=start; i<=(nums.size()-k); i++){

            if(i>start && nums[i] == nums[i-1]) continue;
            std::vector<std::vector<int>> temp = kSum(nums, target-nums[i], k-1, i+1);

            for(auto &vec: temp){
                vec.emplace_back(nums[i]);
                res.emplace_back(vec);
            }
        }
    }

//    for(auto it: res){
//        for(auto its:it){
//            printf("%d\t", its);
//        }
//        printf("\n");
//    }
//    printf("here\n");

    return res;
}

std::vector<std::vector<int>> recurseFourSum(std::vector<int> nums, int target){

    std::vector<std::vector<int>> all_solutions;
    std::sort(nums.begin(), nums.end(), std::less<int>());

    for(auto it: nums){
        printf("%d\t", it);
    }
    printf("\n");

    all_solutions = kSum(nums, target, 4, 0);

    for(auto it: all_solutions){
        for(auto its:it){
            printf("%d\t", its);
        }
        printf("\n");
    }

    return all_solutions;
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

}
