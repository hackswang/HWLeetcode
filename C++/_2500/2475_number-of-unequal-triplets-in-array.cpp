#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/number-of-unequal-triplets-in-array/

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {

        vector<int> all_keys;
        unordered_map<int, int> cache_map;

        for (int i=0; i<nums.size(); i++) {
            if (cache_map.find(nums[i]) == cache_map.end()) {
                cache_map[nums[i]] = 1;
                all_keys.push_back(nums[i]);
            } else {
                cache_map[nums[i]]++;
            }
        }

        if (all_keys.size() < 3) { return 0; }

        int result = 0;
        for(int i=0; i<all_keys.size()-2; i++) {
            for(int j=i+1; j<all_keys.size()-1; j++) {
                for(int k=j+1; k<all_keys.size(); k++) {
                    result += cache_map[all_keys[i]] * cache_map[all_keys[j]] * cache_map[all_keys[k]];
                }
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {4,4,2,4,3,5};
        int result = solution.unequalTriplets(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}