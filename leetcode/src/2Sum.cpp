//
// Created by victor on 2020/10/6.
//

#include "2Sum.h"

#include <unordered_map>
#include <algorithm>

namespace TwoSum {

std::vector<int> nums_(){
    return {2, 7, 11, 15};
}

int target_(){
    return 9;
}

std::vector<int> twoSum(std::vector<int> nums, int target){

  for(auto it: nums){
    printf("%d\t", it);
  }
  printf("\n");

  std::unordered_map<int, int> hashtable;
  for(int i = 0; i<nums.size(); i++){

    auto it = hashtable.find(target - nums[i]);n
    if(it != hashtable.end()){

      printf("%d\t %d \n", it->second, i);
      return {it->second, (i)};
    }
    hashtable[nums[i]] = i;
  }

  return {};
}

}
