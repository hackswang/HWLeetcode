#include <iostream>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int r_5 = 0;
        int r_10 = 0;

        bool allProcessed = true;

        for (int i=0; i<bills.size(); i++) {
            if (bills[i] == 5) {
                r_5++;
            } else if (bills[i] == 10) {
                if (r_5 > 0) {
                    r_5 -= 1;
                    r_10 += 1;
                } else {
                    allProcessed = false;
                    break;
                }
            } else if (bills[i] == 20) {
                if (r_10 > 0 && r_5 > 0) {
                    r_5 -= 1;
                    r_10 -= 1;
                } else if (r_5 >= 3) {
                    r_5 -= 3;
                } else {
                    allProcessed = false;
                    break;
                }
            }
        }

        return allProcessed;
    }
};

int main() {

    Solution solution;
    // {
    //     vector<int> input = {5,5,5,10,20};
    //     bool result = solution.lemonadeChange(input);
    //     cout << endl;
    // }
    // {
    //     vector<int> input = {5,5,10,10,20};
    //     bool result = solution.lemonadeChange(input);
    //     cout << endl;
    // }
    {
        vector<int> input = {5,5,5,20};
        bool result = solution.lemonadeChange(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}