#include <iostream>

using namespace std;

// https://leetcode.cn/problems/backspace-string-compare/

/*
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

 
示例 1：

输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。


示例 2：

输入：s = "ab##", t = "c#d#"
输出：true
解释：s 和 t 都会变成 ""。


示例 3：

输入：s = "a#c", t = "b"
输出：false
解释：s 会变成 "c"，但 t 仍然是 "b"。
 

提示：

1 <= s.length, t.length <= 200
s 和 t 只含有小写字母以及字符 '#'
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        for (int i=0; i<s.size(); i++) {
            if (s[i]=='#') {
                if (i==0) { 
                    s.erase(i, 1); 
                    i -= 1;
                } else {
                    s.erase(i-1, 2); 
                    i -= 2;
                }
            }
        }
        for (int i=0; i<t.size(); i++) {
            if (t[i]=='#') {
                if (i==0) { 
                    t.erase(i, 1); 
                    i -= 1;
                } else {
                    t.erase(i-1, 2); 
                    i -= 2;
                }
            }
        }
        return s==t;
    }
};

int main() {

    Solution solution;
    // {
    //     bool result = solution.backspaceCompare("ab#c", "ad#c");
    //     cout << endl;
    // }
    {
        bool result = solution.backspaceCompare("ab##", "c#d#");
        cout << endl;
    }
    cout << "end";

    return 0;
}