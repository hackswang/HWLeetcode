#include <iostream>

using namespace std;

// https://leetcode.cn/problems/binary-tree-preorder-traversal/


/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

 

示例 1：

输入：root = [1,null,2,3]
输出：[1,2,3]


示例 2：

输入：root = []
输出：[]


示例 3：

输入：root = [1]
输出：[1]


示例 4：

输入：root = [1,2]
输出：[1,2]


示例 5：

输入：root = [1,null,2]
输出：[1,2]
 

提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 

进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> preorderTraversal(TreeNode* root) {
        // Plan A
        // if (root == NULL) { return {}; }
        // vector<int> result;
        // preorderTraversal(root, result);
        // return result;

        // Plan B
        if (root == NULL) { return {}; }
        vector<TreeNode*> cache = {root};
        vector<int> result;
        while (!cache.empty()) {
            result.push_back(cache[0]->val);
            if (cache[0]->right != NULL) {
                cache.insert(cache.begin()+1, cache[0]->right);
            }
            if (cache[0]->left != NULL) {
                cache.insert(cache.begin()+1, cache[0]->left);
            }
            cache.erase(cache.begin());
        }
        return result;
    }

    void preorderTraversal(TreeNode* root, vector<int>& result) {
        result.push_back(root->val);
        if (root->left != NULL) {
            preorderTraversal(root->left, result);
        }
        if (root->right != NULL) {
            preorderTraversal(root->right, result);
        }
    }
};

int main() {

    Solution solution;
    {
        TreeNode *input = new TreeNode(1);
        input->right = new TreeNode(2);
        input->right->left = new TreeNode(3);
        vector<int> result = solution.preorderTraversal(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}