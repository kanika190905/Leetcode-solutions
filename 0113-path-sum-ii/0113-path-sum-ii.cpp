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
    vector<vector<int>> ans;
void solve(TreeNode* root,int target,bool &flag,vector<int> &temp){
        if(root==NULL){
          
            return;
        }
       
        if((target-root->val==0 && root->left==NULL && root->right==NULL)  ){
            flag=true;
              temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        solve(root->left,target-root->val,flag,temp);
         
        
        solve(root->right,target-root->val,flag,temp);
         temp.pop_back();

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        bool flag;
        vector<int> temp;
        solve(root,targetSum,flag,temp);
        return ans;
    }
};