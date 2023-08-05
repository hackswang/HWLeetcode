
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        std::string::size_type found = haystack.find(needle);
        if (found == string::npos) {
            return -1;
        }
        return (int)found;
    }
};


int main() {

    Solution solution;

    cout << solution.strStr("sadbutsad", "sad") << endl;
    cout << solution.strStr("leetcode", "leeto") << endl;

    return 0;
}

