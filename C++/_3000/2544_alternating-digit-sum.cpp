#include <iostream>

using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int flag = 1;
        int result = 0;
        while (n != 0) {
            result += n % 10 * flag;
            n = n / 10;
            flag *= n > 0 ? -1 : 1;
        }
        return result * flag;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.alternateDigitSum(521);
        cout << endl;
    }
    {
        int result = solution.alternateDigitSum(37678263);
        cout << endl;
    }
    {
        int result = solution.alternateDigitSum(886996);
        cout << endl;
    }
    cout << "end";

    return 0;
}