#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dynamic;
        for(int i = 0; i<= amount; i++) {
            dynamic.push_back(amount+1);
        }

        dynamic[0] = 0;

        for (int i = 0; i <= amount; i ++) {
            for (int c : coins) {
                if ((i - c) >= 0) {
                    dynamic[i] = min(dynamic[i], 1 + dynamic[i - c]);
                }
            }
        }

        if (dynamic[amount] == amount+1) {
            return -1;
        }
        return dynamic[amount];
    }
};
