#include <iostream>

using namespace std;

// https://leetcode.cn/problems/average-of-levels-in-binary-tree/


/*
给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。

 
示例 1：

输入：root = [3,9,20,null,null,15,7]
输出：[3.00000,14.50000,11.00000]
解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
因此返回 [3, 14.5, 11] 。


示例 2:

输入：root = [3,9,20,15,7]
输出：[3.00000,14.50000,11.00000]
 

提示：

树中节点数量在 [1, 104] 范围内
-231 <= Node.val <= 231 - 1
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<TreeNode*> stack = {root};
        while (!stack.empty()) {
            long long sum = 0;
            vector<TreeNode*> tmp;
            for (auto item : stack) {
                sum += item->val;
                if (item->left != NULL) { tmp.push_back(item->left); }
                if (item->right != NULL) { tmp.push_back(item->right); }
            }
            result.push_back(sum * 1.0 / stack.size());
            stack = tmp;
        }
        return result;
    }
};

int main() {

    Solution solution;
    {
        // [3,9,20,null,null,15,7]
        TreeNode* input = new TreeNode(3);
        input->left = new TreeNode(9);
        input->right = new TreeNode(20);
        input->right->left = new TreeNode(15);
        input->right->right = new TreeNode(7);
        vector<double> result = solution.averageOfLevels(input);
        cout << endl;
    }
    {
        // [3,9,20,null,null,15,7]
        TreeNode* input = new TreeNode(2147483647);
        input->left = new TreeNode(2147483647);
        input->right = new TreeNode(2147483647);
        vector<double> result = solution.averageOfLevels(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}