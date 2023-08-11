#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/longest-palindrome/


/*
给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。

在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。

 
示例 1:

输入:s = "abccccdd"
输出:7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。


示例 2:

输入:s = "a"
输出:1


示例 3：

输入:s = "aaaaaccc"
输出:7
 

提示:

1 <= s.length <= 2000
s 只由小写 和/或 大写英文字母组成
*/


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cache;
        for (int i=0; i<s.size(); i++) {
            cache[s[i]]++;
        }
        bool addodd = false;
        int result = 0;
        for (auto item : cache) {
            if (item.second % 2 == 0) {
                result += item.second;
            } else {
                result += item.second - 1;
                if (!addodd) {
                    result++;
                    addodd = true;
                }
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.longestPalindrome("abccccdd");
        cout << endl;
    }
    {
        int result = solution.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
        cout << endl;
    }
    cout << "end";

    return 0;
}