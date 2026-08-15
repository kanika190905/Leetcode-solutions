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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        auto left=solve(root->left);
        auto right=solve(root->right);
        int take=root->val+left.second+right.second;
        int notTake=max(left.first,left.second)+max(right.first,right.second);
        return {take,notTake};
    }
    
    int rob(TreeNode* root) {
      pair<int,int> ans=solve(root);
      return max(ans.first,ans.second); 
    }
};