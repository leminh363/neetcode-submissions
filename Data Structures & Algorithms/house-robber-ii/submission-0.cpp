#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int robrange(vector<int>& nums, int start, int end){ 
        vector<int> state(nums.size());

        state[start] = nums[start];
        state[start+1] = max(nums[start],nums[start+1]);

        for(int i = start+2; i<=end; i++) {
            state[i] = max(state[i-1],state[i-2] + nums[i]);
        }
        return state[end];
    }
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


        int rob1 = robrange(nums,0,nums.size()-2);
        int rob2 = robrange(nums,1,nums.size()-1);

        return max(rob1,rob2);
    }
};
