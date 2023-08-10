#include <iostream>

using namespace std;

// https://leetcode.cn/problems/binary-tree-paths/


/*
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。

 
示例 1：

输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]


示例 2：

输入：root = [1]
输出：["1"]
 

提示：

树中节点的数目在范围 [1, 100] 内
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root != NULL) { 
            binaryTreePaths(root, "", result);
        }
        return result;
    }

    void binaryTreePaths(TreeNode* root, string path, vector<string>& result) {

        path += ((path.empty() ? "" : "->") + to_string(root->val));

        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
        } else {
            if (root->left != NULL) {
                binaryTreePaths(root->left, path, result);
            }
            if (root->right != NULL) {
                binaryTreePaths(root->right, path, result);
            }
        }
    }
};

int main() {

    Solution solution;
    {
        // [1,2,3,null,5]
        TreeNode *input = new TreeNode(1);
        input->left = new TreeNode(2);
        input->right = new TreeNode(3);
        input->left->right = new TreeNode(5);
        vector<string> result = solution.binaryTreePaths(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}