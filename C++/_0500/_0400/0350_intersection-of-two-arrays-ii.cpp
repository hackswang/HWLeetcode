#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/intersection-of-two-arrays-ii/


/*
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

 
示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]


示例 2:

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]
 

提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map_1;
        unordered_map<int, int> map_2;

        for (int num : nums1) { map_1[num]++; }
        for (int num : nums2) { map_2[num]++; }

        vector<int> result;
        for (auto item : map_1) {
            if (map_2.find(item.first) != map_2.end()) {
                for (int i=0; i<min(item.second, map_2[item.first]); i++) {
                    result.push_back(item.first);
                }
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
        vector<int> result = solution.intersect(input1, input2);
        cout << endl;
    }
    {
        vector<int> input1 = {4,9,5};
        vector<int> input2 = {9,4,9,8,4};
        vector<int> result = solution.intersect(input1, input2);
        cout << endl;
    }
    cout << "end";

    return 0;
}