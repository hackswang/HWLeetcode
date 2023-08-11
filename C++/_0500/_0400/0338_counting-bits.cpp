#include <iostream>

using namespace std;

// https://leetcode.cn/problems/counting-bits/


/*
给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。


示例 1：

输入：n = 2
输出：[0,1,1]
解释：
0 --> 0
1 --> 1
2 --> 10


示例 2：

输入：n = 5
输出：[0,1,1,2,1,2]
解释：
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

提示：

0 <= n <= 105
 

进阶：

很容易就能实现时间复杂度为 O(n log n) 的解决方案，你可以在线性时间复杂度 O(n) 内用一趟扫描解决此问题吗？
你能不使用任何内置函数解决此问题吗？（如，C++ 中的 __builtin_popcount ）
*/


class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> result = {0};

        int step = 1;
        int index = 1;

        while (index <= n) {
            for (int i=0; i<step && index<=n; i++) {
                result.push_back(result[index - step] + 1);
                index++;
            }
            step *= 2;
        }
        return result;
    }

// 0 --> 0         0
// 1 --> 1         1

// 2 --> 10        1
// 3 --> 11        2

// 4 --> 100       1
// 5 --> 101       2
// 6 ->  110       2
// 7     111       3

// 8     1000      1
// 9     1001      2
// 10    1010      2
//       1011      3
//       1100      2
//       1101      3
//       1110      3
//       1111      4
};

int main() {

    Solution solution;
    {
        vector<int> result = solution.countBits(0);
        cout << endl;
    }
    {
        vector<int> result = solution.countBits(1);
        cout << endl;
    }
    {
        vector<int> result = solution.countBits(2);
        cout << endl;
    }
    {
        vector<int> result = solution.countBits(5);
        cout << endl;
    }
    cout << "end";

    return 0;
}