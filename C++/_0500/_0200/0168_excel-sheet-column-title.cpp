#include <iostream>

using namespace std;

// https://leetcode.cn/problems/excel-sheet-column-title/


/*
给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。

例如：

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

示例 1：

输入：columnNumber = 1
输出："A"


示例 2：

输入：columnNumber = 28
输出："AB"


示例 3：

输入：columnNumber = 701
输出："ZY"


示例 4：

输入：columnNumber = 2147483647
输出："FXSHRXW"
 

提示：

1 <= columnNumber <= 231 - 1
*/


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            int tmp = columnNumber % 26;
            if (tmp > 0) {
                result.insert(0, 1, ('A' + columnNumber % 26 - 1));
                columnNumber /= 26;
            } else if (tmp == 0) {
                result.insert(0, 1, 'Z');
                columnNumber /= 26;
                columnNumber -= 1;
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    // {
    //     string result = solution.convertToTitle(1);
    //     cout << result;
    //     cout << endl;
    // }
    // {
    //     string result = solution.convertToTitle(28);
    //     cout << result;
    //     cout << endl;
    // }
    {
        string result = solution.convertToTitle(52);
        cout << result;
        cout << endl;
    }
    {
        string result = solution.convertToTitle(701);
        cout << result;
        cout << endl;
    }
    {
        string result = solution.convertToTitle(727);
        cout << result;
        cout << endl;
    }
    // {
    //     string result = solution.convertToTitle(2147483647);
    //     cout << result;
    //     cout << endl;
    // }
    cout << "end";

    return 0;
}