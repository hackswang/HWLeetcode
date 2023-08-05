#include <iostream>

using namespace std;

// https://leetcode.cn/problems/find-the-array-concatenation-value/

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        //
        long long result = 0;
        //
        int i = 0;
        while (i<nums.size() / 2) {
            result += getUnionNum(nums[i], nums[nums.size() - 1 - i]);
            i++;
        }
        //
        if (nums.size() % 2 == 1) {
            result += nums[i];
        }
        return result;
    }

    long long getUnionNum(long long num1, long long num2) {
        long long factor = 1;
        while (factor <= num2) {
            factor *= 10;
        }
        return num1 * factor + num2;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {7,52,2,4};
        long long result = solution.findTheArrayConcVal(input);
        cout << endl;
    }
    {
        vector<int> input = {5,14,13,8,12};
        long long result = solution.findTheArrayConcVal(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}