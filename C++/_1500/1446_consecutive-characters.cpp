#include <iostream>

using namespace std;

//  https://leetcode-cn.com/problems/consecutive-characters

/*
 给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。
 
 请你返回字符串的能量。
 
 
 示例 1:
 输入：s = "leetcode"
 输出：2
 解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
 
 示例 2:
 输入：s = "abbcccddddeeeeedcba"
 输出：5
 解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
 
 示例 3:
 输入：s = "triplepillooooow"
 输出：5
 
 示例 4:
 输入：s = "hooraaaaaaaaaaay"
 输出：11
 
 示例 5:
 输入：s = "tourist"
 输出：1
 
 
 提示:
 1 <= s.length <= 500
 s 只包含小写英文字母。
 */

class Solution {
public:
    int maxPower(string s) {

        if (s.size()==1) { return 1; }

        char pre_char = s[0];
        int pre_index = 0;
        int result = 0;

        for (int i=1; i<s.size(); i++) {
            if (s[i] != pre_char) {
                result = max(result, i - pre_index);
                pre_char = s[i];
                pre_index = i;
            }
        }
        result = max(result, (int)(s.size()-pre_index));
        return result;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.maxPower("CC");
        cout << endl;
    }
    {
        int result = solution.maxPower("aabbbbbccccdddddddeffffffggghhhhhiiiiijjjkkkkkllllmmmmmnnnnnoopppqrrrrsssttttuuuuvvvvwwwwwwwxxxxxyyyzzzzzzzz");
        cout << endl;
    }
    {
        int result = solution.maxPower("leetcode");
        cout << endl;
    }
    {
        int result = solution.maxPower("abbcccddddeeeeedcba");
        cout << endl;
    }
    {
        int result = solution.maxPower("triplepillooooow"); // 5
        cout << endl;
    }
    {
        int result = solution.maxPower("hooraaaaaaaaaaay"); // 11
        cout << endl;
    }
    {
        int result = solution.maxPower("tourist");  // 1
        cout << endl;
    }
    cout << "end";

    return 0;
}