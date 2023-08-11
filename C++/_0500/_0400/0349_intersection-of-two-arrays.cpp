#include <iostream>
#include <unordered_set>

using namespace std;

// https://leetcode.cn/problems/intersection-of-two-arrays/


/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。


示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]


示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
 

提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set_1(nums1.begin(), nums1.end());
        unordered_set<int> set_2(nums2.begin(), nums2.end());
        vector<int> result;
        for (auto item : set_1) {
            if (set_2.find(item) != set_2.end()) {
                result.push_back(item);
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input1 = {1,2,2,1};
        vector<int> input2 = {2,2};
        vector<int> result = solution.intersection(input1, input2);
        cout << endl;
    }
    cout << "end";

    return 0;
}