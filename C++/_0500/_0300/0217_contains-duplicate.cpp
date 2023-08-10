#include <iostream>
#include <unordered_set>

using namespace std;

// https://leetcode.cn/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> cache(nums.begin(), nums.end());
        return cache.size() != nums.size();

        unordered_set <int> cache;
        for (int i=0; i<nums.size(); i++) {
            if (cache.find(nums[i]) != cache.end()) {
                return true;
            } else {
                cache.insert(nums[i]);
            }
        }
        return false;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1,2,3,1};
        bool result = solution.containsDuplicate(input);
        cout << endl;
    }
    {
        vector<int> input = {1,2,3,4};
        bool result = solution.containsDuplicate(input);
        cout << endl;
    }
    {
        vector<int> input = {1,1,1,3,3,4,3,2,4,2};
        bool result = solution.containsDuplicate(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}