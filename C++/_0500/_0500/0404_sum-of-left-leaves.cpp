#include <iostream>

using namespace std;

// https://leetcode.cn/problems/sum-of-left-leaves/


/*
给定二叉树的根节点 root ，返回所有左叶子之和。

 
示例 1：

输入: root = [3,9,20,null,null,15,7] 
输出: 24 
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24


示例 2:

输入: root = [1]
输出: 0
 

提示:

节点数在 [1, 1000] 范围内
-1000 <= Node.val <= 1000
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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }

    int sumOfLeftLeaves(TreeNode* root, bool isLeft) {
        if (root->left == NULL && root->right == NULL) {
            return isLeft ? root->val : 0;
        } else {
            int sum = 0;
            if (root->left != NULL) {
                sum += sumOfLeftLeaves(root->left, true);
            }
            if (root->right != NULL) {
                sum += sumOfLeftLeaves(root->right, false);
            }
            return sum;
        } 
    }
};

int main() {

    Solution solution;
    {
        // [3,9,20,null,null,15,7] 
        TreeNode *input = new TreeNode(3);
        input->left = new TreeNode(9);
        input->right = new TreeNode(20);
        input->right->left = new TreeNode(15);
        input->right->right = new TreeNode(7);
        int result = solution.sumOfLeftLeaves(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}