#include <iostream>

using namespace std;

// https://leetcode.cn/problems/rectangle-overlap/


/*
矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。矩形的上下边平行于 x 轴，左右边平行于 y 轴。

如果相交的面积为 正 ，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。

给出两个矩形 rec1 和 rec2 。如果它们重叠，返回 true；否则，返回 false 。

 
示例 1：

输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
输出：true


示例 2：

输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
输出：false


示例 3：

输入：rec1 = [0,0,1,1], rec2 = [2,2,3,3]
输出：false
 

提示：

rect1.length == 4
rect2.length == 4
-109 <= rec1[i], rec2[i] <= 109
rec1 和 rec2 表示一个面积不为零的有效矩形
*/


class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if ((rec1[0] > rec2[0] && rec1[0] < rec2[2]) || 
            (rec1[2] > rec2[0] && rec1[2] < rec2[2]) || 
            (rec1[0] <= rec2[0] && rec1[2] >= rec2[2]) || 
            (rec1[0] >= rec2[0] && rec1[2] <= rec2[2])) {
            return (rec1[1] > rec2[1] && rec1[1] < rec2[3]) || 
                    (rec1[3] > rec2[1] && rec1[3] < rec2[3]) || 
                    (rec1[1] <= rec2[1] && rec1[3] >= rec2[3]) || 
                    (rec1[1] >= rec2[1] && rec1[3] <= rec2[3]);
        }
        return false;
    }
};

int main() {

    Solution solution;
    {
        vector<int> input1 = {0,0,2,2};
        vector<int> input2 = {1,1,3,3};
        bool result = solution.isRectangleOverlap(input1, input2);
        cout << endl;
    }
    {
        vector<int> input1 = {0,0,1,1};
        vector<int> input2 = {1,0,2,1};
        bool result = solution.isRectangleOverlap(input1, input2);
        cout << endl;
    }
    {
        vector<int> input1 = {0,0,1,1};
        vector<int> input2 = {2,2,3,3};
        bool result = solution.isRectangleOverlap(input1, input2);
        cout << endl;
    }
    {
        vector<int> input1 = {2,17,6,20};
        vector<int> input2 = {3,8,6,20};
        bool result = solution.isRectangleOverlap(input1, input2);
        cout << endl;
    }
    cout << "end";

    return 0;
}