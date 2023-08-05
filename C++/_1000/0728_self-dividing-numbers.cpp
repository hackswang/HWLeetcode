#include <iostream>

using namespace std;

// https://leetcode.cn/problems/self-dividing-numbers/

// 自除数 是指可以被它包含的每一位数整除的数。

// 例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
// 自除数 不允许包含 0 。

// 给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。

 

// 示例 1：

// 输入：left = 1, right = 22
// 输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
// 示例 2:

// 输入：left = 47, right = 85
// 输出：[48,55,66,77]
 

// 提示：

// 1 <= left <= right <= 104

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i=left; i<=right; i++) {
            if (isSelfDividingNumbers(i)) {
                result.push_back(i);
            }
        }
        return result;
    }

    bool isSelfDividingNumbers(int num) {
        if (num < 10) { return true; }
        int cache = num;
        while (cache > 0) {
            if (cache % 10 == 0 || num % (cache % 10) != 0) {
                return false;
            }
            cache /= 10;
        }
        return true;
    }
};

int main() {

    Solution solution;
    {
        vector<int> result = solution.selfDividingNumbers(47, 85);
        cout << endl;
    }
    cout << "end";

    return 0;
}