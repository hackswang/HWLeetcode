#include <iostream>

using namespace std;

// https://leetcode.cn/problems/maximum-average-subarray-i/


/*
给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。

请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。

任何误差小于 10-5 的答案都将被视为正确答案。


示例 1：

输入：nums = [1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75


示例 2：

输入：nums = [5], k = 1
输出：5.00000
 

提示：

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
*/


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i=0; i<k; i++) {
            sum += nums[i];
        }
        double result = sum * 1.0 / k;
        for (int i=1; i<=nums.size()-k; i++) {
            sum -= nums[i-1];
            sum += nums[i+k-1];
            result = max(result, sum * 1.0 / k);
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1,12,-5,-6,50,3};
        double result = solution.findMaxAverage(input, 4);
        cout << endl;
    }
    {
        vector<int> input = {5};
        double result = solution.findMaxAverage(input, 1);
        cout << endl;
    }
    cout << "end";

    return 0;
}