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
    int ans;
    int cnt;
    bool found;
public:
    void inorder(TreeNode* root,int k){
        if(root==NULL) return;
        if(found) return ;
        if(found==0)
        inorder(root->left,k);
        else return;
        cnt++;
        if(cnt==k){
            ans=root->val;
            found=true;
            return;
        }
        if(found==0)
        inorder(root->right,k);
        else return;
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt=0;
        found=0;
        inorder(root,k);
        return ans;
    }
};