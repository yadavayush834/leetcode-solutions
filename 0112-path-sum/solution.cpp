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
    bool dfs(TreeNode* root, int remaining){
        if(root == nullptr){
            return false;
        }
        remaining -= root->val;
        if(root->left == nullptr && root->right == nullptr){
            return remaining == 0;
        }
        return dfs(root->left,remaining) || dfs(root->right,remaining);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum);
        
    }
};
