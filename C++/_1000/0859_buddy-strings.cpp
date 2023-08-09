#include <iostream>
#include <unordered_set>

using namespace std;

// https://leetcode.cn/problems/buddy-strings/

/*
给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。

交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。

例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
 

示例 1：

输入：s = "ab", goal = "ba"
输出：true
解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。


示例 2：

输入：s = "ab", goal = "ab"
输出：false
解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。


示例 3：

输入：s = "aa", goal = "aa"
输出：true
解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
 

提示：

1 <= s.length, goal.length <= 2 * 104
s 和 goal 由小写英文字母组成
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if (s.size() != goal.size()) { return false; }

        char ex_s = '0';
        char ex_g = '0';
        for (int i=0; i<s.size(); i++) {
            if (s[i] == goal[i]) { 
                continue; 
            } else if (ex_s == '0' && ex_g == '0') {
                ex_s = s[i];
                ex_g = goal[i];
            } else if (ex_s == '1' && ex_g == '1') {
                return false;
            } else if (ex_s == goal[i] && ex_g == s[i]) {
                ex_s = '1';
                ex_g = '1';
            } else {
                return false;
            }
        }
        if (ex_s == '0' && ex_g == '0') {
            if (s.size() > 26) {
                return true;
            } else {
                unordered_set<char> cache(s.begin(), s.end());
                return cache.size() < s.size();
            }
        } 
        return (ex_s == '1' && ex_g == '1');
    }
};

int main() {

    Solution solution;
    {
        bool result = solution.buddyStrings("ab", "ba");
        cout << endl;
    }
    {
        bool result = solution.buddyStrings("ab", "ab");
        cout << endl;
    }
    {
        bool result = solution.buddyStrings("aa", "aa");
        cout << endl;
    }
    cout << "end";

    return 0;
}