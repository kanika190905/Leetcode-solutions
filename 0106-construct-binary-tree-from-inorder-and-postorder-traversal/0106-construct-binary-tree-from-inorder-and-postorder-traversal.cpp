class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& postorder,int postStart,int postEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int> &m){
        if(postStart>postEnd || inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inRoot=m[root->val];
        int numsLeft=inRoot-inStart;
        root->right=buildTree(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,m);
        root->left=buildTree(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inRoot-1,m);
        return root;
    }
};