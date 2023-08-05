#include <iostream>

using namespace std;

// https://leetcode.cn/problems/prime-arrangements/

vector<int> cache = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

class Solution {
public:
    int numPrimeArrangements(int n) {
        //
        if (n <= 2) { return 1; }
        //
        int index = 0;
        while (cache[index] <= n) {
            index++;
        }
        //
        long long result = 1;

        for (int i = n - index; i >= 2; i--) {
            result *= i;
            if (result > (1000000000 + 7)) {
                result %= (1000000000 + 7);
            }
        }
        for (int i = index; i >= 2; i--) {
            result *= i;
            if (result > (1000000000 + 7)) {
                result %= (1000000000 + 7);
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.numPrimeArrangements(11);
        cout << endl;
    }
    cout << "end";

    return 0;
}