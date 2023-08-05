#include <iostream>
#include <string>

using namespace std;

// https://leetcode.cn/problems/to-lower-case/description/

class Solution {
public:
    string toLowerCase(string s) {
        for(auto &c : s)  
            c = tolower(c);
        return s;
    }
};

int main() {

    Solution solution;
    {
        string result = solution.toLowerCase("Hello");
        cout << result;
        cout << endl;
    }
    cout << "end";

    return 0;
}