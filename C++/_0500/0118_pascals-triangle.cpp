#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> cache;
        for (int i=0; i<numRows; i++) {
            vector<int> tmp;
            for (int j=0; j<=i; j++) {
                tmp.push_back((j > 0 && j < i) ? (cache[j-1] + cache[j]) : 1);
            }
            result.push_back(tmp);
            cache = tmp;
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<vector<int>> result = solution.generate(5);
        cout << endl;
    }
    cout << "end";

    return 0;
}