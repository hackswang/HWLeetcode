#include <iostream>

using namespace std;

// https://leetcode.cn/problems/three-consecutive-odds/


// 给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。

 
// 示例 1：

// 输入：arr = [2,6,4,1]
// 输出：false
// 解释：不存在连续三个元素都是奇数的情况。
// 示例 2：

// 输入：arr = [1,2,34,3,4,5,7,23,12]
// 输出：true
// 解释：存在连续三个元素都是奇数的情况，即 [5,7,23] 。
 

// 提示：

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000


class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int i=0; i<arr.size(); i++) {  
            if (arr[i] % 2 == 1) {
                count++;
            } else {
                count = 0;
            }
            if (count >= 3) {
                return true;
            }
        }
        return false;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {1,2,1,1};
        bool result = solution.threeConsecutiveOdds(input);
        cout << endl;
    }
    {
        vector<int> input = {1,2,34,3,4,5,7,23,12};
        bool result = solution.threeConsecutiveOdds(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}