#include <iostream>

using namespace std;

// https://leetcode.cn/problems/max-consecutive-ones/


/*
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。


示例 1：

输入：nums = [1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.


示例 2:

输入：nums = [1,0,1,1,0,1]
输出：2
 

提示：

1 <= nums.length <= 105
nums[i] 不是 0 就是 1.
*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, sum = 0;
        for (int i=0; i<=nums.size(); i++) {
            if (i == nums.size() || nums[i] == 0) { result = max(result, sum); sum = 0; continue; }
            if (nums[i] == 1) { sum += 1; }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1,1,0,1,1,1};
        int result = solution.findMaxConsecutiveOnes(input);
        cout << endl;
    }
    {
        vector<int> input = {1,0,1,1,0,1};
        int result = solution.findMaxConsecutiveOnes(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}