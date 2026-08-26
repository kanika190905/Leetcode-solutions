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
    void solve(int l,int r,map<pair<int,int>,vector<int>> &mp,TreeNode* root){
        if(root==NULL){
            return;
        }
       mp[{r, l}].push_back(root->val);  
        solve(l+1,r-1,mp,root->left);
        solve(l+1,r+1,mp,root->right);
        

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>> mp;
        solve(0,0,mp,root);
       vector<vector<int>> ans;
           int prev = INT_MIN;

        for(auto &it : mp){
            int col = it.first.first;

            if(col != prev){
                ans.push_back({});
                prev = col;
            }

            sort(it.second.begin(), it.second.end());

            for(int x : it.second){
                ans.back().push_back(x);
            }
        }

        return ans;

        


        
    }
};