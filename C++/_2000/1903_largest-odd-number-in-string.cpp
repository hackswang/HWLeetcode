#include <iostream>

using namespace std;

// https://leetcode.cn/problems/largest-odd-number-in-string/description/

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i=num.size()-1; i>=0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};

int main() {

    Solution solution;
    {
        string result = solution.largestOddNumber("123123246");
        cout << result;
        cout << endl;
    }
    cout << "end";

    return 0;
}