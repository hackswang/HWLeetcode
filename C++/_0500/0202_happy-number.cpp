#include <iostream>
#include <unordered_set>

using namespace std;

// https://leetcode.cn/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {

        unordered_set <int> hash_table;

        int cache = n;
        while (1) {
            int sum = 0;
            while (cache > 0) {
                int l = cache % 10;
                sum += l * l;
                cache /= 10;
            }
            if (sum == 1) {
                return true;
            } else if (hash_table.find(sum) != hash_table.end()) {
                return false;
            } else {
                cache = sum;
                hash_table.insert(sum);
            }
        }
        return false;
    }
};

int main() {

    Solution solution;
    {
        bool result = solution.isHappy(19);
        cout << endl;
    }
    {
        bool result = solution.isHappy(2);
        cout << endl;
    }
    cout << "end";

    return 0;
}