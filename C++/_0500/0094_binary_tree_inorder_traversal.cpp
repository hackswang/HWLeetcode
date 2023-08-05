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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root != NULL) {
            realInorder(root, result);
        }
        return result;
    }

    void realInorder(TreeNode* root, vector<int>& result) {
        if (root->left != NULL) {
            realInorder(root->left, result);
        }
        result.push_back(root->val);
        if (root->right != NULL) {
            realInorder(root->right, result);
        }
    }
};

int main() {
    Solution solution;

    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);

    node1.right = &node2;
    node2.left = &node3;

    vector<int> result = solution.inorderTraversal(&node1);

    cout << "end";

    return 0;
}