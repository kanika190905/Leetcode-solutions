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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        int maxWidth=0;
        q.push({root,0});
        while(!q.empty()){
            unsigned long long stIdx=q.front().second;
           unsigned long long endIdx=q.back().second;
            int size=q.size();
            maxWidth=max(maxWidth,(int)(endIdx-stIdx+1));
            for(int i=0;i<size;i++){
                auto p=q.front();
                unsigned long long x=p.second;
                if(p.first->left)
                    q.push({p.first->left,2*x +1});
                if(p.first->right)
                    q.push({p.first->right,2*x +2});
                q.pop();
            }

        }
        return maxWidth;
    }
};