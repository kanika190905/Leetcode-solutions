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
   pair<int,int> dfs(TreeNode* root,map<TreeNode*, pair<int,int>> &mp){
    if(root==NULL){
        return {0,0};
    }
    if(mp[root].first!=0 && mp[root].second!=0){
        return mp[root];
    }
     int sum=root->val;
     int cnt=1;
     sum+=dfs(root->left,mp).first+dfs(root->right,mp).first;
     cnt+=dfs(root->left,mp).second+dfs(root->right,mp).second;
     return mp[root]={sum,cnt};
   } 
   
    int averageOfSubtree(TreeNode* root) {
        map<TreeNode*, pair<int,int>> mp;
        pair<int,int> p;
        p=dfs(root,mp);
        int ans=0;
        for(auto [node,sum_count]:mp){
            int sum=sum_count.first;
            int cnt=sum_count.second;
            int avg=sum/cnt;
            if(node->val==avg) ans++;
           
        }
        return ans;
    }
};