#include <iostream>

using namespace std;

// https://leetcode.cn/problems/day-of-the-year/

class Solution {
public:
    int dayOfYear(string date) {
        int month = atoi(date.substr(5, 2).c_str());
        int day = atoi(date.substr(8, 2).c_str());
        int result = 0;
        if (month > 1) { result += 31; }
        if (month > 2) { 
            int year = atoi(date.substr(0, 4).c_str());
            result += (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) ? 29 : 28;
        }
        if (month > 3) { result += 31; }
        if (month > 4) { result += 30; }
        if (month > 5) { result += 31; }
        if (month > 6) { result += 30; }
        if (month > 7) { result += 31; }
        if (month > 8) { result += 31; }
        if (month > 9) { result += 30; }
        if (month > 10) { result += 31; }
        if (month > 11) { result += 30; }
        result += day;
        return result;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.dayOfYear("2019-11-21");
        cout << endl;
    }
    {
        int result = solution.dayOfYear("2019-02-10");
        cout << endl;
    }
    cout << "end";

    return 0;
}