#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/set-mismatch/


/*
集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。

给定一个数组 nums 代表了集合 S 发生错误后的结果。

请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。


示例 1：

输入：nums = [1,2,2,4]
输出：[2,3]


示例 2：

输入：nums = [1,1]
输出：[1,2]
 

提示：

2 <= nums.length <= 104
1 <= nums[i] <= 104
*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int num_copy = 0;
        int num_last = 0;

        unordered_map <int, int> num_map;
        
        for (int i=0; i<nums.size(); i++) {
            num_map[nums[i]]++;
        }
        for (int i=1; i<=nums.size(); i++) {
            if (num_map[i] == 2) { num_copy = i; }
            if (num_map[i] == 0) { num_last = i; }
        }
        return {num_copy, num_last};
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1,2,2,4};
        vector<int> result = solution.findErrorNums(input);
        cout << endl;
    }
    {
        vector<int> input = {1,1};
        vector<int> result = solution.findErrorNums(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}