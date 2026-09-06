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
    void helper(TreeNode* root, vector<vector<int>>&res, vector<int>&curr,int sum){
        if(root == NULL) return;
        curr.push_back(root->val);
        if(root->left == NULL && root->right ==NULL && sum == root->val){
            res.push_back(curr);

        }
        helper(root->left,res,curr,sum-root->val);
        helper(root->right,res,curr,sum-root->val);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>curr;
        vector<vector<int>>res;
        helper(root,res,curr,targetSum);
        return res;
    }
};
