#include <iostream>

using namespace std;

// https://leetcode.cn/problems/1-bit-and-2-bit-characters/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int size = bits.size();
        if (size == 1) { return true; }
        if (bits[size - 2] == 0) { return true; }
        int zero_index = size - 2;
        while (zero_index >= 0 && bits[zero_index] == 1) {
            zero_index--;
        }
        return (size - 1 - zero_index) % 2 == 1;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1, 1, 1, 0};
        bool result = solution.isOneBitCharacter(input);
        cout << endl;
    }
    {
        vector<int> input = {1, 0, 1, 1, 1, 0};
        bool result = solution.isOneBitCharacter(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}