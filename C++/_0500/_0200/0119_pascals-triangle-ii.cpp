#include <iostream>

using namespace std;

// https://leetcode.cn/problems/pascals-triangle-ii/


/*
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。


示例 1:

输入: rowIndex = 3
输出: [1,3,3,1]


示例 2:

输入: rowIndex = 0
输出: [1]


示例 3:

输入: rowIndex = 1
输出: [1,1]
 

提示:

0 <= rowIndex <= 33
 

进阶：

你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {1};
        for (int i=0; i<rowIndex; i++) {
            int pre = result[0];
            for (int j=1; j<result.size(); j++) {
                int tmp = result[j];
                result[j] = result[j] + pre;
                pre = tmp;
            }
            result.push_back(1);
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<int> result = solution.getRow(3);
        cout << endl;
    }
    {
        vector<int> result = solution.getRow(0);
        cout << endl;
    }
    {
        vector<int> result = solution.getRow(1);
        cout << endl;
    }
    {
        vector<int> result = solution.getRow(6);
        cout << endl;
    }
    cout << "end";

    return 0;
}