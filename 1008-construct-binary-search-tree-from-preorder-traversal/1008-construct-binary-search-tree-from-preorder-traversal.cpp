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
    TreeNode* bstFromPreorder(vector<int>& preorder,int start1,int end1) {
        if(preorder.size()==0  ||end1<start1) return NULL;
        TreeNode* root=new TreeNode(preorder[start1]);
        if(end1==start1) return root;
        int start2=end1+1;
        for(int i=start1+1;i<=end1;i++){
            if(preorder[i]>preorder[start1]){
                 start2=i;
                break;
            }
        }
        root->left=bstFromPreorder(preorder,start1+1,start2-1);
        root->right=bstFromPreorder(preorder,start2,end1);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorder(preorder,0,preorder.size()-1);
    }
};