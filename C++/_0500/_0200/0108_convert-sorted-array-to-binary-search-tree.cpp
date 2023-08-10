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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int count = nums.size();
        int center = count / 2;
        return newTreeNode(nums, 0, count-1);
    }

    TreeNode* newTreeNode(vector<int>& nums, int left, int right) {
        if (left > right) { return NULL; }
        int center = (left + right) / 2;
        TreeNode *node = new TreeNode(nums[center]);
        node->left = newTreeNode(nums, left, center-1);
        node->right = newTreeNode(nums, center+1, right);
        return node;
    }
};

int main() {

    Solution solution;

    {
        vector<int> input = {-10,-3,0,5,9};
        TreeNode *result = solution.sortedArrayToBST(input);
        cout << "end";
    }
    {
        vector<int> input = {1,3};
        TreeNode *result = solution.sortedArrayToBST(input);
        cout << "end";
    }

    cout << "end";

    return 0;
}