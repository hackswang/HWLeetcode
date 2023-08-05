#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int size = nums.size();

        if (size == 0) { return; }

        int point = 0;
        while (point < size) {
            if (nums[point] == 0) {
                nums.erase(nums.begin() + point);
                nums.push_back(0);
                size--;
            } else {
                point++;
            }
        }
    }
};

int main() {

    Solution solution;

    {
        vector<int> input = {0, 1, 0, 3, 12};
        solution.moveZeroes(input);
        cout << endl;
    }
    {
        vector<int> input = {1, 0, 0, 0, 0, 0, 0, 0, 0};
        solution.moveZeroes(input);
        cout << endl;
    }
    {
        vector<int> input = {0, 0, 0, 0, 0, 0, 0, 0, 1};
        solution.moveZeroes(input);
        cout << endl;
    }
    {
        vector<int> input = {0};
        solution.moveZeroes(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}