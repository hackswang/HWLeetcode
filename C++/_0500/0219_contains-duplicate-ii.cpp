#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> cache;
        for (int i=0; i<nums.size(); i++) {
            auto iterator = cache.find(nums[i]);
            if (iterator == cache.end()) {
                cache[nums[i]] = i;
            } else if (i - iterator->second <= k) {
                return true;
            } else {
                cache[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1,2,3,1};
        bool result = solution.containsNearbyDuplicate(input, 3);
        cout << endl;
    }
    {
        vector<int> input = {1,0,1,1};
        bool result = solution.containsNearbyDuplicate(input, 1);
        cout << endl;
    }
    {
        vector<int> input = {1,2,3,1,2,3};
        bool result = solution.containsNearbyDuplicate(input, 2);
        cout << endl;
    }
    cout << "end";

    return 0;
}