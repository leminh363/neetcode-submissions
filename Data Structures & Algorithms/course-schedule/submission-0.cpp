#include<iostream>
#include<math.h>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> graph;
    vector<int> state;
    
    // 0 havent visited
    // 1 visiting
    // 2 done visiting
    bool dfs(int course) {
        state[course] = 1;
        for (int i=0; i<graph[course].size(); i++) {
            int next = graph[course][i];
            if (state[next] == 1) {
                return true;
            }
            else if (state[next] == 0) {
                if (dfs(next)) {
                    return true;
                }
            }
            else {
                continue;
            }
        }
        state[course] = 2;
        return false;   
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>> (numCourses);
        state = vector<int>(numCourses, 0);

        for (int i=0; i<prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (dfs(i)) {
                return false;
            }
        }
        return true;
    }
};


/* int main() {
    int numCourses = 2; 
    vector<vector<int>>prerequisities = {{0,1}};
    Solution sol;
    cout << sol.canFinish(numCourses, prerequisities);
} */ 