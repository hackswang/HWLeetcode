#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.cn/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size()) { return false; }
        
        unordered_map <int, int> hash_map_s_t;
        unordered_map <int, int> hash_map_t_s;

        for (int i=0; i<s.size(); i++) {
            auto iterator_s = hash_map_s_t.find(s[i]);
            auto iterator_t = hash_map_t_s.find(t[i]);
            if (iterator_s == hash_map_s_t.end() && iterator_t == hash_map_t_s.end()) {
                hash_map_s_t[s[i]] = t[i];
                hash_map_t_s[t[i]] = s[i];
            } else {
                if (hash_map_s_t[s[i]] == t[i] && hash_map_t_s[t[i]] == s[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

    Solution solution;
    {
        bool result = solution.isIsomorphic("egg", "add");
        cout << endl;
    }
    {
        bool result = solution.isIsomorphic("foo", "bar");
        cout << endl;
    }
    {
        bool result = solution.isIsomorphic("paper", "title");
        cout << endl;
    }
    {
        bool result = solution.isIsomorphic("badc", "baba");
        cout << endl;
    }
    cout << "end";

    return 0;
}