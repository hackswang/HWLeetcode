#include <iostream>

using namespace std;

// https://leetcode.cn/problems/minimum-absolute-difference/

// 给你个整数数组 arr，其中每个元素都 不相同。

// 请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

// 每对元素对 [a,b] 如下：

// a , b 均为数组 arr 中的元素
// a < b
// b - a 等于 arr 中任意两个元素的最小绝对差
 

// 示例 1：

// 输入：arr = [4,2,1,3]
// 输出：[[1,2],[2,3],[3,4]]
// 示例 2：

// 输入：arr = [1,3,6,10,15]
// 输出：[[1,3]]
// 示例 3：

// 输入：arr = [3,8,-10,23,19,-4,-14,27]
// 输出：[[-14,-10],[19,23],[23,27]]

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        //
        sort(arr.begin(), arr.end());
        //
        int minDiff = arr[1] - arr[0];
        for (int i=2; i<arr.size(); i++) {
            minDiff = min(minDiff,  arr[i] - arr[i-1]);
        }
        //
        vector<vector<int>> result;
        for (int i=1; i<arr.size(); i++) {
            if (arr[i] - arr[i-1] == minDiff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input = {4,2,1,3};
        vector<vector<int>> result = solution.minimumAbsDifference(input);
        cout << endl;
    }
    {
        vector<int> input = {1,3,6,10,15};
        vector<vector<int>> result = solution.minimumAbsDifference(input);
        cout << endl;
    }
    {
        vector<int> input = {3,8,-10,23,19,-4,-14,27};
        vector<vector<int>> result = solution.minimumAbsDifference(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}