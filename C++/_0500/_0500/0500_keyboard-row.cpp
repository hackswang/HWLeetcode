#include <iostream>

using namespace std;

// https://leetcode.cn/problems/keyboard-row/


/*
给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

美式键盘 中：

第一行由字符 "qwertyuiop" 组成。
第二行由字符 "asdfghjkl" 组成。
第三行由字符 "zxcvbnm" 组成。
American keyboard

 
示例 1：

输入：words = ["Hello","Alaska","Dad","Peace"]
输出：["Alaska","Dad"]


示例 2：

输入：words = ["omk"]
输出：[]


示例 3：

输入：words = ["adsdf","sfd"]
输出：["adsdf","sfd"]
 

提示：

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] 由英文字母（小写和大写字母）组成
*/


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int i=0, flag=-1;
        while (i < words.size()) {
            flag = getFlag(words[i][0]);
            for (int j=1; j<words[i].size(); j++) {
                if (getFlag(words[i][j]) != flag) {
                    flag = -1; break;
                }
            }
            if (flag == -1) { words.erase(words.begin() + i); }
            else { i++; }
        }
        return words;
    }

    int getFlag(char c) {
        if ('A' <= c && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        if (c == 'q' || c == 'w' || c == 'e' || c == 'r' || c == 't' || c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'p') {
            return 1;
        } else if (c == 'a' || c == 's' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || c == 'j' || c == 'k' || c == 'l') {
            return 2;
        } else if (c == 'z' || c == 'x' || c == 'c' || c == 'v' || c == 'b' || c == 'n' || c == 'm') {
            return 3;
        }
        return -1;
    }
};

int main() {

    Solution solution;
    {
        vector<string> input = {"Hello","Alaska","Dad","Peace"};
        vector<string> result = solution.findWords(input);
        cout << endl;
    }
    {
        vector<string> input = {"omk"};
        vector<string> result = solution.findWords(input);
        cout << endl;
    }
    {
        vector<string> input = {"adsdf","sfd"};
        vector<string> result = solution.findWords(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}