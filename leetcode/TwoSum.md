### 1. Two Sum


```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int i,j;

        for(i=0; i< nums.size(); i++){
            for(j=i+1; j<nums.size(); j++){
                if( target == (nums[i] + nums[j])){
                    return vector<int> {i,j};
                }
            }
        }
        return {i,j};
        
    }
};
```
