#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/sort-array-by-increasing-frequency/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        // 降维 - 数字-频率映射
        unordered_map<int, int> n_f_map;
        for (int i=0; i<nums.size(); i++) {
            n_f_map[nums[i]]++;
        }

        // 降维 - 频率-数字映射
        unordered_map<int, vector<int>> f_n_map;
        for (auto n_f : n_f_map) {
            f_n_map[n_f.second].push_back(n_f.first);
        }

        // 按频率排序
        vector<int> keys;
        for (auto f_n : f_n_map) {
            keys.push_back(f_n.first);
        }
        sort(keys.begin(), keys.end());

        // 结果填充
        vector<int> result; 
        for (int i=0; i<keys.size(); i++) {
            // 多余一个降序排列
            if (f_n_map[keys[i]].size() > 1) {
                sort(f_n_map[keys[i]].begin(), f_n_map[keys[i]].end(), greater<int>());
            }
            // 结果填充
            for (int j=0; j<f_n_map[keys[i]].size(); j++) {
                for (int k=0; k<keys[i]; k++) {
                    result.push_back(f_n_map[keys[i]][j]);
                }
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1,1,2,2,2,3};
        vector<int> result = solution.frequencySort(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}