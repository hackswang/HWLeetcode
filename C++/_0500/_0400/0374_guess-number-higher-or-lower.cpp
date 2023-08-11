#include <iostream>

using namespace std;

// https://leetcode.cn/problems/guess-number-higher-or-lower/


/*
猜数字游戏的规则如下：

每轮游戏，我都会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
如果你猜错了，我会告诉你，你猜测的数字比我选出的数字是大了还是小了。
你可以通过调用一个预先定义好的接口 int guess(int num) 来获取猜测结果，返回值一共有 3 种可能的情况（-1，1 或 0）：

-1：我选出的数字比你猜的数字小 pick < num
1：我选出的数字比你猜的数字大 pick > num
0：我选出的数字和你猜的数字一样。恭喜！你猜对了！pick == num
返回我选出的数字。

 
示例 1：

输入：n = 10, pick = 6
输出：6


示例 2：

输入：n = 1, pick = 1
输出：1


示例 3：

输入：n = 2, pick = 1
输出：1


示例 4：

输入：n = 2, pick = 2
输出：2
 

提示：

1 <= n <= 231 - 1
1 <= pick <= n
*/


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if (n==1) { return 1; }

<<<<<<< Updated upstream
        int head = 1;
        int tail = n;

        int guess_num;
        int guess_result;
=======
        long long head = 1;
        long long tail = n;
        long long guess_num;
        long long guess_result;
>>>>>>> Stashed changes
        while (head < tail)  {
            guess_num = (head + tail) / 2;
            guess_result = guess(guess_num);
            if (guess_result == -1) {
                tail = guess_num;
            } else if (guess_result == 1) {
                head = guess_num;
                if (head + 1 == tail) { return tail; }
            } else { 
                return guess_num; 
            }
        }
        return tail;
    }

    int guess(int num) {
        // int result = 6;
        int result = 2;
        if (num < result) {
            return 1;
        }
        if (num > result) {
            return -1;
        }
        return 0;
    }
};

int main() {

    Solution solution;
    // {
    //     int result = solution.guessNumber(10);
    //     cout << endl;
    // }
    {
        int result = solution.guessNumber(2);
        cout << endl;
    }
    cout << "end";

    return 0;
}