#include <iostream>

using namespace std;

// https://leetcode.cn/problems/find-the-pivot-integer/

class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1) { return 1; }
        if (n <= 7) { return -1; }
        int sum = n * (n + 1) / 2;
        for (int x=n-1; x>n/2; x--) {
            if (x * x == sum) { // x * (x + 1) == sum + x   // f(n) - f(x) + x = f(x)   // f(n) = n * (n + 1) / 2
                return x;
            }
        }
        return -1;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.pivotInteger(27);
        cout << endl;
    }
    cout << "end";

    return 0;
}