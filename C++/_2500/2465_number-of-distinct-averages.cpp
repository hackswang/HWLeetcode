#include <iostream>
#include <unordered_set>

using namespace std;

// https://leetcode.cn/problems/number-of-distinct-averages/

class Solution {
public:
    int distinctAverages(vector<int>& nums) {

        unordered_set<float> avg_cache;

        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size() / 2; i++) {
            avg_cache.insert((nums[i] + nums[nums.size() - 1- i]) * 1.0 / 2.0);
        }
        return avg_cache.size();
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {4,1,4,0,3,5};
        int result = solution.distinctAverages(input);
        cout << endl;
    }
    {
        vector<int> input = {1, 100};
        int result = solution.distinctAverages(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}