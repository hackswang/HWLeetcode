#include <iostream>

using namespace std;

// https://leetcode.cn/problems/reverse-string/


/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

 
示例 1：

输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]


示例 2：

输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
 

提示：

1 <= s.length <= 105
s[i] 都是 ASCII 码表中的可打印字符
*/


class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        for (int i=0; i<s.size()/2; i++) {
            tmp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = tmp;
        }
    }
};

int main() {

    Solution solution;
    {
        vector<char> input = {'h','e','l','l','o'};
        solution.reverseString(input);
        cout << endl;
    }
    {
        vector<char> input = {};
        solution.reverseString(input);
        cout << endl;
    }
    {
        vector<char> input = {'h'};
        solution.reverseString(input);
        cout << endl;
    }
    {
        vector<char> input = {'h','e','l','l','o','w'};
        solution.reverseString(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}