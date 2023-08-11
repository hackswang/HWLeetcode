#include <iostream>

using namespace std;

// https://leetcode.cn/problems/invert-binary-tree/


/*
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

 
示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]


示例 2：

输入：root = [2,1,3]
输出：[2,3,1]


示例 3：

输入：root = []
输出：[]
 

提示：

树中节点数目范围在 [0, 100] 内
-100 <= Node.val <= 100
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) { return NULL; }
        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

int main() {

    Solution solution;
    {
        // [4,2,7,1,3,6,9]
        TreeNode *input = new TreeNode(4);
        input->left = new TreeNode(2);
        input->right = new TreeNode(7);
        input->left->left = new TreeNode(1);
        input->left->right = new TreeNode(3);
        input->right->left = new TreeNode(6);
        input->right->right = new TreeNode(9);
        TreeNode *result = solution.invertTree(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}