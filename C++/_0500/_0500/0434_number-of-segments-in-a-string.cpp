#include <iostream>

using namespace std;

// https://leetcode.cn/problems/number-of-segments-in-a-string/


/*
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
*/


class Solution {
public:
    int countSegments(string s) {
        int i = 0, result = 0;
        while (i < s.size()) {
            if (s[i] == ' ') { i++; continue; }
            result++;
            while (s[i] != ' ' && i < s.size()) {
                i++;
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.countSegments("Hello, my name is John");
        cout << endl;
    }
    {
        int result = solution.countSegments("Hello");
        cout << endl;
    }
    {
        int result = solution.countSegments("Hello  ,   my   name   is   John");
        cout << endl;
    }
    cout << "end";

    return 0;
}