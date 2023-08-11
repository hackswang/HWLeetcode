#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/ransom-note/


/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

 
示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false


示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false


示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true
 

提示：

1 <= ransomNote.length, magazine.length <= 105
ransomNote 和 magazine 由小写英文字母组成
*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> cache;
        for (int i=0; i<magazine.size(); i++) {
            cache[magazine[i]]++;
        }
        for (int i=0; i<ransomNote.size(); i++) {
            if (cache.find(ransomNote[i]) == cache.end()) {
                return false;
            } else if (cache[ransomNote[i]] == 0) {
                return false;
            } else {
                cache[ransomNote[i]]--;
            }
        }
        return true;
    }
};

int main() {

    Solution solution;
    {
        bool result = solution.canConstruct("a", "b");
        cout << endl;
    }
    {
        bool result = solution.canConstruct("aa", "ab");
        cout << endl;
    }
    {
        bool result = solution.canConstruct("aa", "aab");
        cout << endl;
    }
    cout << "end";

    return 0;
}