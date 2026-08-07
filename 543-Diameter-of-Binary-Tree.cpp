/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxDiameter = 0;

    int calculateDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);

        maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);

        return std::max(leftDepth, rightDepth) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        calculateDepth(root);
        
        return maxDiameter;
    }
};