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
    int minDepth(TreeNode* root) {
        if (root == NULL) { return 0; }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        } else if (root->left == NULL) {
            return minDepth(root->right) + 1;
        } else if (root->right == NULL) {
            return minDepth(root->left) + 1;
        } else {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
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

        int result = solution.minDepth(root);
        cout << "end";
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(3);
        // root->left->right = new TreeNode(3);
        root->left->left->left = new TreeNode(4);
        // root->left->left->right = new TreeNode(4);
        root->right->left = new TreeNode(2);

        int result = solution.minDepth(root);
        cout << "end";
    }

    cout << "end";

    return 0;
}