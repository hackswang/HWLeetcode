#include <iostream>

using namespace std;

// https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/


/*
给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。

 
示例 1：

输入: root = [5,3,6,2,4,null,7], k = 9
输出: true


示例 2：

输入: root = [5,3,6,2,4,null,7], k = 28
输出: false
 

提示:

二叉树的节点个数的范围是  [1, 104].
-104 <= Node.val <= 104
题目数据保证，输入的 root 是一棵 有效 的二叉搜索树
-105 <= k <= 105
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
    bool findTarget(TreeNode* root, int k) {
        if (root->left == NULL && root->right == NULL) { return false; }
        vector<int> cache;
        createArray(root, cache);
        int i_1 = 0;
        int i_2 = cache.size()-1;
        for (int i=cache.size()-1; i>=0; i--) {
            for (int j=0; j<i; j++) {
                if (cache[i] + cache[j] == k) { 
                    return true; 
                }
                if (cache[i] + cache[j] > k) { break; }
            }
        }
        return false;
    }

    void createArray(TreeNode* root, vector<int>& cache) {
        if (root->left != NULL) { createArray(root->left, cache); }
        cache.push_back(root->val);
        if (root->right != NULL) { createArray(root->right, cache); }
    }
};

int main() {

    Solution solution;
    {
        // [5,3,6,2,4,null,7]
        TreeNode *input = new TreeNode(5);
        input->left = new TreeNode(3);
        input->right = new TreeNode(6);
        input->left->left = new TreeNode(2);
        input->left->right = new TreeNode(4);
        input->right->right = new TreeNode(7);
        bool result = solution.findTarget(input, 9);
        cout << endl;
    }
    {
        // [1,0,4,-2,null,3]
        TreeNode *input = new TreeNode(1);
        input->left = new TreeNode(0);
        input->right = new TreeNode(4);
        input->left->left = new TreeNode(-2);
        input->right->left = new TreeNode(3);
        bool result = solution.findTarget(input, 7);
        cout << endl;
    }
    {
        // [5,3,6,2,4,null,7]
        TreeNode *input = new TreeNode(5);
        input->left = new TreeNode(3);
        input->right = new TreeNode(6);
        input->left->left = new TreeNode(2);
        input->left->right = new TreeNode(4);
        input->right->right = new TreeNode(7);
        bool result = solution.findTarget(input, 28);
        cout << endl;
    }
    {
        // [1,0,4,-2,null,3]
        TreeNode *input = new TreeNode(2);
        input->left = new TreeNode(1);
        input->right = new TreeNode(3);
        bool result = solution.findTarget(input, 4);
        cout << endl;
    }
    {
        // [0,-3,2,-4,null,1]
        TreeNode *input = new TreeNode(0);
        input->left = new TreeNode(-3);
        input->right = new TreeNode(2);
        input->left->left = new TreeNode(-4);
        input->right->left = new TreeNode(1);
        bool result = solution.findTarget(input, 1);
        cout << endl;
    }
    cout << "end";

    return 0;
}