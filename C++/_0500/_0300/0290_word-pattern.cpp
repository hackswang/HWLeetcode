#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/word-pattern/


/*
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。

 
示例1:

输入: pattern = "abba", s = "dog cat cat dog"
输出: true


示例 2:

输入:pattern = "abba", s = "dog cat cat fish"
输出: false


示例 3:

输入: pattern = "aaaa", s = "dog cat cat dog"
输出: false
 

提示:

1 <= pattern.length <= 300
pattern 只包含小写英文字母
1 <= s.length <= 3000
s 只包含小写英文字母和 ' '
s 不包含 任何前导或尾随对空格
s 中每个单词都被 单个空格 分隔
*/


class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> map_p_s;
        unordered_map<string, char> map_s_p;

        s += " ";

        int i_p = 0;
        int i_s = 0;
        int i_t = 0;

        while (i_p<pattern.size() && i_s<s.size()) {
            i_t = i_s;
            while (s[i_s] != ' ') {
                i_s++;
            }
            string sub_s = s.substr(i_t, i_s - i_t);
            if (map_p_s.find(pattern[i_p]) == map_p_s.end() && map_s_p.find(sub_s) == map_s_p.end()) {
                map_p_s[pattern[i_p]] = sub_s;
                map_s_p[sub_s] = pattern[i_p];
            } else if (map_p_s[pattern[i_p]] != sub_s || map_s_p[sub_s] != pattern[i_p]) {
                return false;
            }
            i_p++;
            i_s++;
        }
        if (i_p == pattern.size() && i_s == s.size()) {
            return true;
        }
        return false;
    }
};

int main() {

    Solution solution;
    {
        bool result = solution.wordPattern("abba", "dog cat cat dog");
        cout << endl;
    }
    {
        bool result = solution.wordPattern("abba", "dog cat cat fish");
        cout << endl;
    }
    {
        bool result = solution.wordPattern("aaaa", "dog cat cat dog");
        cout << endl;
    }
    {
        bool result = solution.wordPattern("abba", "cat cat cat cat");
        cout << endl;
    }
    cout << "end";

    return 0;
}