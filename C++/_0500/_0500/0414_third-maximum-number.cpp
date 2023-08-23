#include <iostream>

using namespace std;

// https://leetcode.cn/problems/third-maximum-number/


/*
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。

 
示例 1：

输入：[3, 2, 1]
输出：1
解释：第三大的数是 1 。
示例 2：

输入：[1, 2]
输出：2
解释：第三大的数不存在, 所以返回最大的数 2 。
示例 3：

输入：[2, 2, 3, 1]
输出：1
解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
 

提示：

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
*/


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1) { return nums[0]; }
        if (nums.size() == 2) { return max(nums[0], nums[1]); }

        int f = nums[0], s = nums[0], t = nums[0];

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == f || nums[i] == s || nums[i] == t) { continue; }
            if (nums[i] > f) { t = s; s = f; f = nums[i]; }
            else if (nums[i] > s) { t = s; s = nums[i]; }
            else if (nums[i] > t) { t = nums[i]; }
            else {
                if (f == s && s == t) { s = nums[i]; t = nums[i]; }
                else if (s == t) { t = nums[i]; } 
            }
        }
        return s == t ? f : t;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {3, 2, 1};
        int result = solution.thirdMax(input);
        cout << endl;
    }
    {
        vector<int> input = {1, 2};
        int result = solution.thirdMax(input);
        cout << endl;
    }
    {
        vector<int> input = {2, 2, 3, 1};
        int result = solution.thirdMax(input);
        cout << endl;
    }
    {
        vector<int> input = {2, 2, 3};
        int result = solution.thirdMax(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}