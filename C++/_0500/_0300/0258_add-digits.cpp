#include <iostream>

using namespace std;

// https://leetcode.cn/problems/add-digits/


/*
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。

 
示例 1:

输入: num = 38
输出: 2 
解释: 各位相加的过程为：
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
由于 2 是一位数，所以返回 2。


示例 2:

输入: num = 0
输出: 0
 

提示：

0 <= num <= 231 - 1
 

进阶：你可以不使用循环或者递归，在 O(1) 时间复杂度内解决这个问题吗？
*/


class Solution {
public:
    int addDigits(int num) {
        // 9 进制？
        // 0
        // 1 10 19 1
        // 2 11 20 29 38 47 56 65 74 83 92 101 110 119  2
        // 3 12 21 30 39 3
        // 13  4
        // 14  5
        // 15  6
        // 16  7
        // 17  8
        // 9 18 27 36 9
        if (num == 0) { return 0; }
        if (num % 9 == 0) {
            return 9;
        } else {
            return num % 9;
        }
    }
};

int main() {

    Solution solution;
    {
        int result = solution.addDigits(0);
        cout << endl;
    }
    {
        int result = solution.addDigits(38);
        cout << endl;
    }
    {
        int result = solution.addDigits(386);
        cout << endl;
    }
    cout << "end";

    return 0;
}