/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNzode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, int currentSum, vector<int>& path, vector<vector<int>>& result){
        if(!root){
            return;
        }

        currentSum += root -> val;
        path.push_back(root -> val);

        if(!root -> left && !root -> right && currentSum == targetSum){
            result.push_back(path);
        } else {
            solve(root->left, targetSum, currentSum, path, result);
            solve(root->right, targetSum, currentSum, path, result);
        }

        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        
        solve(root, targetSum, 0, path, result);
        
        return result;
    }
};