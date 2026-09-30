#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) {
            return min(cost[0],cost[1]);
        }
        else if (cost.size() == 1) {
            return cost[0];
        }
        else if (cost.size() == 0) {
            return 0;
        }

        vector<int> floor(cost.size());
        
        floor[0] = cost[0];
        floor[1] = cost[1];
        for(int i=2; i < cost.size(); i++) {
            floor[i] = min(cost[i]+floor[i-1],cost[i]+floor[i-2]);
        }
        return min(floor[cost.size()-1],floor[cost.size()-2]);
    }
};
