
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n>3) {
            return climbStairs(n-1) + climbStairs(n-2);
        } else if (n==1) {
            return 1;
        } else if (n==2) {
            return 2;
        } else if (n==3) {
            return 3;
        } else {
            return 0;
        }
    }
};


int main() {

    Solution solution;

    cout << solution.climbStairs(2) << endl;
    cout << solution.climbStairs(3) << endl; 
    cout << solution.climbStairs(15) << endl; // 987
    cout << solution.climbStairs(25) << endl; // 121393

    return 0;
}