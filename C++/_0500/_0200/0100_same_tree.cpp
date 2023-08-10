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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameNode(p, q);
    }

    bool isSameNode(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) { return true; }
        else if (p == NULL && q != NULL) { return false; }
        else if (p != NULL && q == NULL) { return false; }
        else {
            if (p->val != q->val) { return false; }
            else if (!isSameNode(p->left, q->left)) { return false; }
            else if (!isSameNode(p->right, q->right)) { return false; }
            else { return true; }
        }
    }
};

int main() {

    Solution solution;

    // TreeNode node11 = TreeNode(1);
    // TreeNode node12 = TreeNode(2);
    // TreeNode node13 = TreeNode(3);
    // node11.left = &node12;
    // node11.right = &node13;

    // TreeNode node21 = TreeNode(1);
    // TreeNode node22 = TreeNode(2);
    // TreeNode node23 = TreeNode(3);
    // node21.left = &node22;
    // node21.right = &node23;

    // bool result = solution.isSameTree(&node11, &node21);

    // TreeNode node11 = TreeNode(1);
    // TreeNode node12 = TreeNode(2);
    // TreeNode node13 = TreeNode(1);
    // node11.left = &node12;
    // node11.right = &node13;

    // TreeNode node21 = TreeNode(1);
    // TreeNode node22 = TreeNode(1);
    // TreeNode node23 = TreeNode(2);
    // node21.left = &node22;
    // node21.right = &node23;

    // bool result = solution.isSameTree(&node11, &node21);

    TreeNode node11 = TreeNode(1);
    TreeNode node12 = TreeNode(2);
    TreeNode node13 = TreeNode(1);
    node11.left = &node12;
    // node11.right = &node13;

    TreeNode node21 = TreeNode(1);
    TreeNode node22 = TreeNode(1);
    TreeNode node23 = TreeNode(2);
    // node21.left = &node22;
    node21.right = &node23;

    bool result = solution.isSameTree(&node11, &node21);

    cout << "end";

    return 0;
}