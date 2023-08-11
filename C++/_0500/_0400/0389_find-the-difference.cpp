#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/find-the-difference/


/*
给定两个字符串 s 和 t ，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。


示例 1：

输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。


示例 2：

输入：s = "", t = "y"
输出："y"
 

提示：

0 <= s.length <= 1000
t.length == s.length + 1
s 和 t 只包含小写字母
*/


class Solution {
public:
    char findTheDifference(string s, string t) {

        unordered_map<char, int> cache;
        for (int i=0; i<s.size(); i++) {
            cache[s[i]]++;
        }
        for (int i=0; i<t.size(); i++) {
            if (cache.find(t[i]) == cache.end() || cache[t[i]] == 0) {
                return t[i];
            } else {
                cache[t[i]]--;
            }
        }
        return 0;
    }
};

int main() {

    Solution solution;
    {
        char result = solution.findTheDifference("abcd", "abcdg");
        cout << endl;
    }
    {
        char result = solution.findTheDifference("", "y");
        cout << endl;
    }
    cout << "end";

    return 0;
}