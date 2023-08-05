#include <iostream>

using namespace std;

// https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array/

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int result = 0;
        for (int i=0; i<strs.size(); i++) {
            int tmp = 0;
            for (int j=0; j<strs[i].size(); j++) {
                if (strs[i][j] >= '0' && strs[i][j] <= '9') {
                    tmp = tmp * 10 + strs[i][j] - '0';
                } else {
                    tmp = 0;
                    result = max(result, (int)strs[i].size());
                    break;
                }
            }
            result = max(result, tmp);
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<string> input = {"alic3","123bob","3","4","00000"};
        int result = solution.maximumValue(input);
        cout << endl;
    }
    {
        vector<string> input = {"1","01","001","0001"};
        int result = solution.maximumValue(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}