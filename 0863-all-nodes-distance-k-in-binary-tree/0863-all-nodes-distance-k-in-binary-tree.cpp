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
    void markParents(unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
            
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markParents(parent,root);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int dist=0;
        while(!q.empty()){
            int n=q.size();
            if(k==dist++) break;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && visited[node->left]==false){
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && visited[node->right]==false){
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if( parent[node] && visited[parent[node]]==false){
                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};