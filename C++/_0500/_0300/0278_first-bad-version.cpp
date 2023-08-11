#include <iostream>

using namespace std;

// https://leetcode.cn/problems/first-bad-version/


/*
你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

 
示例 1：

输入：n = 5, bad = 4
输出：4
解释：
调用 isBadVersion(3) -> false 
调用 isBadVersion(5) -> true 
调用 isBadVersion(4) -> true
所以，4 是第一个错误的版本。


示例 2：

输入：n = 1, bad = 1
输出：1
 

提示：

1 <= bad <= n <= 231 - 1
*/


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        if (n == 1) { return n; }
        if (isBadVersion(1)) { return 1; }

        long long c_v = 1;
        long long f_v = n;

        while (c_v + 1 < f_v) {
            if (isBadVersion((c_v + f_v) / 2)) {
                f_v = (c_v + f_v) / 2;
            } else {
                c_v = (c_v + f_v) / 2;
            }
        }
        return f_v;
    }

    bool isBadVersion(int n) {
        // return n >= 2;
        return n >= 1702766719;
    }
};

int main() {

    Solution solution;
    {
        int result = solution.firstBadVersion(9);
        cout << endl;
    }
    {
        int result = solution.firstBadVersion(2126753390);
        cout << endl;
    }
    cout << "end";

    return 0;
}