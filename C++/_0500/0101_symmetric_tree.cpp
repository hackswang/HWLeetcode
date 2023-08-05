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
    bool isSymmetric(TreeNode* root) {
        return isSymmetricNode(root->left, root->right);
    }

    bool isSymmetricNode(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) { return true; }
        else if (p == NULL && q != NULL) { return false; }
        else if (p != NULL && q == NULL) { return false; }
        else {
            if (p->val != q->val) { return false; }
            else if (!isSymmetricNode(p->left, q->right)) { return false; }
            else if (!isSymmetricNode(p->right, q->left)) { return false; }
            else { return true; }
        }
    }
};

int main() {

    Solution solution;

    // TreeNode node11 = TreeNode(1);
    // TreeNode node12 = TreeNode(2);
    // TreeNode node13 = TreeNode(3);
    // TreeNode node14 = TreeNode(4);
    // TreeNode node15 = TreeNode(2);
    // TreeNode node16 = TreeNode(4);
    // TreeNode node17 = TreeNode(3);
    // node11.left = &node12;
    // node11.right = &node15;
    // node12.left = &node13;
    // node12.right = &node14;
    // node15.left = &node16;
    // node15.right = &node17;

    // bool result = solution.isSymmetric(&node11);

    TreeNode node11 = TreeNode(1);
    TreeNode node12 = TreeNode(2);
    TreeNode node13 = TreeNode(3);
    TreeNode node14 = TreeNode(2);
    TreeNode node15 = TreeNode(3);
    node11.left = &node12;
    node11.right = &node14;
    node12.right = &node13;
    node14.right = &node15;

    bool result = solution.isSymmetric(&node11);

    cout << "end";

    return 0;
}