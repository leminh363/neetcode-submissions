#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> state(nums.size());

        if (nums.size() == 2) {
            return max(nums[0],nums[1]);
        }
        else if (nums.size() == 1) {
            return nums[0];
        }
        else if (nums.size() == 0) {
            return 0;
        }

        state[0] = nums[0];
        state[1] = max(nums[1],nums[0]);
        
        for(int i = 2; i<nums.size(); i++) {
            state[i] = max(state[i-1],state[i-2] + nums[i]);
        }
        return state[nums.size()-1];
    }
};
