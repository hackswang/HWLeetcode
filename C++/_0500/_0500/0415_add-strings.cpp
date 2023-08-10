#include <iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {

        int size1 = num1.size();
        int size2 = num2.size();
        int carry = 0;

        string result = "";

        for (int i=0; i<max(size1, size2); i++) {
            int sub1 = i < size1 ? num1[size1 - 1 - i] - '0' : 0;
            int sub2 = i < size2 ? num2[size2 - 1 - i] - '0' : 0;
            int sum = sub1 + sub2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            result = to_string(sum) + result;
        }

        if (carry == 1) {
            result = "1" + result;
        }

        return result;
    }
};

int main() {

    Solution solution;

    cout << solution.addStrings("11", "123") << endl;
    cout << solution.addStrings("456", "77") << endl;
    cout << solution.addStrings("0", "0") << endl;
    cout << "end";

    return 0;
}