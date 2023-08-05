#include <iostream>

using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (numOnes >= k) { return k; }
        if (k > numOnes + numZeros) { return numOnes - (k - (numOnes + numZeros)); }
        return numOnes;
    }
};

int main() {

    Solution solution;

    {
        int result = solution.kItemsWithMaximumSum(3, 2, 5, 6);
        cout << endl;
    }
    cout << "end";

    return 0;
}