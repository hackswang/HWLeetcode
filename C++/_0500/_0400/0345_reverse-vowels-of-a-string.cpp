#include <iostream>

using namespace std;

// https://leetcode.cn/problems/reverse-vowels-of-a-string/


/*
给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。


示例 1：

输入：s = "hello"
输出："holle"


示例 2：

输入：s = "leetcode"
输出："leotcede"
 

提示：

1 <= s.length <= 3 * 105
s 由 可打印的 ASCII 字符组成
*/


class Solution {
public:
    string reverseVowels(string s) {
        char tmp;
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            while (!isVowel(s[head]) && head < s.size()) {
                head++;
            }
            while (!isVowel(s[tail]) && tail > 0) {
                tail--;
            }
            if (head < tail) {
                tmp = s[head];
                s[head] = s[tail];
                s[tail] = tmp;
                head++;
                tail--;
            }
        }
        return s;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
};

int main() {

    Solution solution;
    {
        string result = solution.reverseVowels("hello");
        cout << result;
        cout << endl;
    }
    cout << "end";

    return 0;
}