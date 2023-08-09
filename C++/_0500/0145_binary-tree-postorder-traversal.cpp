#include <iostream>

using namespace std;

// https://leetcode.cn/problems/binary-tree-postorder-traversal/


/*
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

 
示例 1：

输入：root = [1,null,2,3]
输出：[3,2,1]


示例 2：

输入：root = []
输出：[]


示例 3：

输入：root = [1]
输出：[1]
 

提示：

树中节点的数目在范围 [0, 100] 内
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
    vector<int> postorderTraversal(TreeNode* root) {
        // Plan A
        // if (root == NULL) { return {}; }
        // vector<int> result;
        // postorderTraversal(root, result);
        // return result;

        // Plan B
        if (root == NULL) { return {}; }
        vector<TreeNode*> cache = {root};
        vector<int> result;
        while (!cache.empty()) {
            if (cache[0]->left == NULL && cache[0]->right == NULL) {
                result.push_back(cache[0]->val);
                cache[0] = NULL;
                cache.erase(cache.begin());
                continue;
            }
            TreeNode *tmp = cache[0];
            if (tmp->right != NULL) {
                cache.insert(cache.begin(), tmp->right);
                tmp->right = NULL;
            }
            if (tmp->left != NULL) {
                cache.insert(cache.begin(), tmp->left);
                tmp->left = NULL;
            }
        }
        return result;
    }

    void postorderTraversal(TreeNode* root, vector<int>& result) {
        if (root->left != NULL) {
            postorderTraversal(root->left, result);
        }
        if (root->right != NULL) {
            postorderTraversal(root->right, result);
        }
        result.push_back(root->val);
    }
};  

int main() {

    Solution solution;
    {
        TreeNode *input = new TreeNode(3);
        input->left = new TreeNode(1);
        input->right = new TreeNode(2);
        vector<int> result = solution.postorderTraversal(input);
        cout << endl;
    }
    cout << "end";

    return 0;
}