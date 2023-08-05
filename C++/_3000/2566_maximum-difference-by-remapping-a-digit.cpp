#include <iostream>

using namespace std;

// https://leetcode.cn/problems/maximum-difference-by-remapping-a-digit/

class Solution {
public:
    int minMaxDifference(int num) {

        if (num < 10) { return 9; }

        string max_s = to_string(num);
        string min_s = max_s;

        int index = 0;
        while (max_s[index] == '9') {
            index++;
        }
        if (index < max_s.size()) {
            for (int i=0; i<max_s.size(); i++) {
                if (max_s[i]==max_s[index] && i != index) {
                    max_s[i] = '9';
                }
            }
            max_s[index] = '9';
        }

        for (int i=0; i<min_s.size(); i++) {
            if (min_s[i] == min_s[0] && i != 0) {
                min_s[i] = '0';
            }
        }
        min_s[0] = '0';

        int maxnum = atoi(max_s.c_str());
        int minnum = atoi(min_s.c_str());
        return maxnum - minnum;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.minMaxDifference(11891);
        cout << endl;
    }
    {
        int result = solution.minMaxDifference(99999);
        cout << endl;
    }
    cout << "end";

    return 0;
}