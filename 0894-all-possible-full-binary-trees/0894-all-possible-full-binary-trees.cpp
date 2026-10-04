class Solution {
public:

    vector<TreeNode*> solve(int n) {

        vector<TreeNode*> ans;

        if (n % 2 == 0)
            return ans;

        if (n == 1) {
            ans.push_back(new TreeNode(0));
            return ans;
        }

        for (int leftSize = 1; leftSize < n; leftSize += 2) {

            int rightSize = n - 1 - leftSize;

            vector<TreeNode*> leftTrees = solve(leftSize);
            vector<TreeNode*> rightTrees = solve(rightSize);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* root = new TreeNode(0);

                    root->left = left;
                    root->right = right;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};