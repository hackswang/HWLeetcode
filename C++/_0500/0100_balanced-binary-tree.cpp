#include <iostream>

using namespace std;

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
    bool isBalanced(TreeNode* root) {
        return isBalancedNode(root).first;
    }

    pair<bool, int> isBalancedNode(TreeNode* root) {
        if (root == NULL) { return make_pair(true, 0); }

        pair<bool, int> left = isBalancedNode(root->left);
        pair<bool, int> right = isBalancedNode(root->right);

        if (left.first == false || right.first == false) {
            return make_pair(false, 0);
        } else if (abs(left.second - right.second) > 1) {
            return make_pair(false, 0);
        } else {
            return make_pair(true, max(left.second, right.second) + 1);
        }
    }
};

int main() {

    Solution solution;

    {
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        bool result = solution.isBalanced(root);
        cout << "end";
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(3);
        root->left->left->left = new TreeNode(4);
        root->left->left->right = new TreeNode(4);

        bool result = solution.isBalanced(root);
        cout << "end";
    }

    cout << "end";

    return 0;
}