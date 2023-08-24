#include <iostream>

using namespace std;

// https://leetcode.cn/problems/repeated-substring-pattern/


/*
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

 
示例 1:

输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。


示例 2:

输入: s = "aba"
输出: false


示例 3:

输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成
*/


class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        if (s.size() == 1) { return false; }

        string pre = "", suf = "";
        for (int i=0; i<s.size() / 2; i++) {
            pre = pre + s[i];
            suf = s[s.size() - 1 - i] + suf;
            if (pre == suf && isrRepeatedSubstring(s, pre)) {
                return true;
            }
        }
        return false;
    }

    bool isrRepeatedSubstring(string s, string sub) {
        if (s.size() % sub.size() != 0) { return false; }
        for (int i=0; i<(s.size()/sub.size()); i++) {
            if (s.substr(i*sub.size(), sub.size()) != sub) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    Solution solution;
    {
        bool result = solution.repeatedSubstringPattern("a");
        cout << endl;
    }
    {
        bool result = solution.repeatedSubstringPattern("aba");
        cout << endl;
    }
    {
        bool result = solution.repeatedSubstringPattern("abab");
        cout << endl;
    }
    {
        bool result = solution.repeatedSubstringPattern("abcab");
        cout << endl;
    }
    {
        bool result = solution.repeatedSubstringPattern("abcabcabcabc");
        cout << endl;
    }
    cout << "end";

    return 0;
}