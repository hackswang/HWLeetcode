#include <iostream>

using namespace std;

// https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/

class Solution {
public:
    int numberOfCuts(int n) {
        return n == 1 ? 0 : (n % 2 == 0 ? n / 2 : n);
    }
};

int main() {

    Solution solution;
    {
        int result = solution.numberOfCuts(3);
        cout << endl;
    }
    cout << "end";

    return 0;
}