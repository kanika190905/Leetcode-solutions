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
 class BSTIterator {
private: 
    stack<TreeNode*> s;
    bool reverse=false;
public:
    BSTIterator(TreeNode* root,bool reverse1) {
        reverse=reverse1;
        pushAll(root,reverse);
    }
    void pushAll(TreeNode* node,bool reverse){
        while(node){
            s.push(node);
            if(reverse==false)
            node=node->left;
            else
            node=node->right;
        }
    }
    
    int next() {
        TreeNode* temp=s.top();
        s.pop();
        if (!reverse) {
        pushAll(temp->right, false);
    } else {
        pushAll(temp->left, true);
    }
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
       if(root==NULL) return false;
       BSTIterator l(root,false);
       BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            if(i+j <k){
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
       return false;
    }
};