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
    void solve(TreeNode* root,int target,bool &flag){
        if(root==NULL){
            return;
        }
        if((target-root->val==0 && root->left==NULL && root->right==NULL) || flag ){
            flag=true;
            return;
        }
       
        solve(root->left,target-root->val,flag);
        
        solve(root->right,target-root->val,flag);
       

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
         if(root==NULL){
            return false;
        }
      
        bool flag=false;
        solve(root,targetSum,flag);
        return flag;
    }
};