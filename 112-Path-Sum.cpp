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
public:
    bool solve(TreeNode* root, int ts, int sum){
        if(!root){
           return false;
        }

        sum += root -> val;

        if(root -> left == NULL && root -> right == NULL){
            if(sum == ts){
                return true;
            } else{
                return false;
            }
        }

        bool left = solve(root -> left, ts, sum);
        bool right = solve(root -> right, ts, sum);

        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        int ans = solve(root, targetSum, sum);
        return ans;
    }
};