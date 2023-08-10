#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/valid-anagram/


/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

 
示例 1:

输入: s = "anagram", t = "nagaram"
输出: true


示例 2:

输入: s = "rat", t = "car"
输出: false
 

提示:

1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母
 

进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        // 不兼容 unicode 直接用 int 作为 key 就行
        unordered_map<string, int> cache;

        for (int i=0; i<s.size(); i++) {
            cache[s.substr(i, 1)]++;
        }
        for (int i=0; i<t.size(); i++) {
            if (cache[t.substr(i, 1)] <= 0) {
                return false;
            } else {
                cache[t.substr(i, 1)]--;
                if (cache[t.substr(i, 1)] <= 0) {
                    cache.erase(t.substr(i, 1));
                }
            }
        }
        return cache.empty();
    }
};

int main() {

    Solution solution;
    {
        int result = solution.isAnagram("anagram", "nagaram");
        cout << endl;
    }
    {
        int result = solution.isAnagram("rat", "car");
        cout << endl;
    }
    cout << "end";

    return 0;
}