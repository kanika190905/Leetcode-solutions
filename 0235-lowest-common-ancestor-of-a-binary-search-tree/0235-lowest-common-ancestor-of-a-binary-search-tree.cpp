/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         TreeNode* temp=root;
        if(temp==NULL) return NULL;
        if(temp->val==p->val|| temp->val==q->val) return temp;
      
        TreeNode* left=lowestCommonAncestor(temp->left,p,q);
        TreeNode* right=lowestCommonAncestor(temp->right,p,q);
        if(left!=NULL && right!=NULL) return temp;
        if(left!=NULL) return left;
        if(right!=NULL) return right;
        return NULL;
    }
   
};