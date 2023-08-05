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
    int maxDepth(TreeNode* root) {
        return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {

    Solution solution;

    TreeNode node11 = TreeNode(1);
    TreeNode node12 = TreeNode(2);
    TreeNode node13 = TreeNode(3);
    TreeNode node14 = TreeNode(4);
    TreeNode node15 = TreeNode(2);
    TreeNode node16 = TreeNode(4);
    TreeNode node17 = TreeNode(3);
    node11.left = &node12;
    node11.right = &node15;
    node12.left = &node13;
    node12.right = &node14;
    node15.left = &node16;
    node15.right = &node17;

    int depth = solution.maxDepth(&node11);

    cout << "end";

    return 0;
}