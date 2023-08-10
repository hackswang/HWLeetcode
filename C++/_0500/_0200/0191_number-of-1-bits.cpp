#include <iostream>

using namespace std;

// https://leetcode.cn/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {

        int result = 0;
        while (n > 0) {
            result += n % 2;
            n /= 2;
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.hammingWeight(0b00000000000000000000000000001011);
        cout << endl;
    }
    {
        int result = solution.hammingWeight(0b00000000000000000000000010000000);
        cout << endl;
    }
    cout << "end";

    return 0;
}