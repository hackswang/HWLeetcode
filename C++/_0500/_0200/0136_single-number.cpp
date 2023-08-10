#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/single-number/


/*
给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

 
示例 1 ：

输入：nums = [2,2,1]
输出：1


示例 2 ：

输入：nums = [4,1,2,1,2]
输出：4


示例 3 ：

输入：nums = [1]
输出：1
 

提示：

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
除了某个元素只出现一次以外，其余每个元素均出现两次。
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // // Plan A
        // unordered_map<int, int> cache;
        // for (int i=0; i<nums.size(); i++) {
        //     cache[nums[i]]++;
        //     if (cache[nums[i]] == 2) {
        //         cache.erase(nums[i]);
        //     }
        // }
        // return cache.begin()->first;

        // Plan B
        int result = nums[0];
        for (int i=1; i<nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {2,2,1};
        int result = solution.singleNumber(input);
        cout << endl;
    }
    {
        vector<int> input = {4,1,2,1,2};
        int result = solution.singleNumber(input);
        cout << endl;
    }
    {
        vector<int> input = {1};
        int result = solution.singleNumber(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}