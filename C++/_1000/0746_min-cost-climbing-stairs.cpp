#include <iostream>

using namespace std;

// https://leetcode.cn/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i=2; i<cost.size(); i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[cost.size()-1], cost[cost.size()-2]);
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1,100,1,1,1,100,1,1,100,1};
        int result = solution.minCostClimbingStairs(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}