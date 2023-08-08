#include <iostream>

using namespace std;

// https://leetcode.cn/problems/maximum-product-of-three-numbers/


/*
给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。


示例 1：

输入：nums = [1,2,3]
输出：6
示例 2：

输入：nums = [1,2,3,4]
输出：24
示例 3：

输入：nums = [-1,-2,-3]
输出：-6
 

提示：

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) { return nums[0] * nums[1] * nums[2]; }
        // 实际上这里直接遍历一遍，把最大的三个正整数和最小的三个负整数取出来更好，懒得写了，就直接排序了，理论可以做到 O(n) 的
        sort(nums.begin(), nums.end());
        //
        if (nums[0] < 0 && nums[1] < 0 && nums[nums.size()-1] >= 0) {
            if (nums[0] * nums[1] >= nums[nums.size()-2] * nums[nums.size()-3]) {
                return nums[nums.size()-1] * nums[0] * nums[1];
            }
        }
        return nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3];
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1,2,3};
        int result = solution.maximumProduct(input);
        cout << endl;
    }
    {
        vector<int> input = {1,2,3,4};
        int result = solution.maximumProduct(input);
        cout << endl;
    }
    {
        vector<int> input = {-1,-2,-3};
        int result = solution.maximumProduct(input);
        cout << endl;
    }
    {
        vector<int> input = {-1,-2, 0, 3};
        int result = solution.maximumProduct(input);
        cout << endl;
    }
    {
        vector<int> input = {-1,-2,-3,-4};
        int result = solution.maximumProduct(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}