#include <iostream>

using namespace std;

// https://leetcode.cn/problems/convert-the-temperature/

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> result;
        result.push_back(celsius + 273.15);
        result.push_back(celsius * 1.8 + 32.0);
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<double> result = solution.convertTemperature(35.12);
        cout << endl;
    }
    cout << "end";

    return 0;
}