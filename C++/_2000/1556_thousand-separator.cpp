#include <iostream>

using namespace std;

// https://leetcode.cn/problems/thousand-separator/


// 给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。

 
// 示例 1：

// 输入：n = 987
// 输出："987"
// 示例 2：

// 输入：n = 1234
// 输出："1.234"
// 示例 3：

// 输入：n = 123456789
// 输出："123.456.789"
// 示例 4：

// 输入：n = 0
// 输出："0"
 

// 提示：

// 0 <= n < 2^31


class Solution {
public:
    string thousandSeparator(int n) {
        if (n<1000) { return to_string(n); }
        string result = "";
        int count = 0;
        while (n>0) {
            if (count == 3) {
                result = "." + result;
                count = 1;
            } else {
                count++;
            }
            result = to_string(n % 10) + result;
            n /= 10;
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        string result = solution.thousandSeparator(51040);
        cout << result;
        cout << endl;
    }
    {
        string result = solution.thousandSeparator(123456789);
        cout << result;
        cout << endl;
    }
    cout << "end";

    return 0;
}