#include <iostream>

using namespace std;

// https://leetcode.cn/problems/majority-element/description/


/*
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 
示例 1：

输入：nums = [3,2,3]
输出：3


示例 2：

输入：nums = [2,2,1,1,1,2,2]
输出：2
 

提示：
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Plan A 
        // 用 map，懒得写了

        // Plan B - 进阶
        // 充分利用多数元素数量多的特点，来玩消消乐，老子人多，老子活到最后
        if (nums.size() == 1) { return nums[0]; }
        for (int i=0; i<nums.size(); i++) {
            if (i >= 0 && i < nums.size()-1 && nums[i] != nums[i+1]) {
                nums.erase(nums.begin() + i + 1);
                nums.erase(nums.begin() + i);
                i = max(-1, i-2);
            }
        }
        return nums[0];
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {3,2,3};
        int result = solution.majorityElement(input);
        cout << endl;
    }
    {
        vector<int> input = {2,2,1,1,1,2,2};
        int result = solution.majorityElement(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}