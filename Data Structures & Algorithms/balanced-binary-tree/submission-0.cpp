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
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {1, 0};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        int height = 1 + max(left[1], right[1]);
        int b = 0;
        if (abs(left[1] - right[1]) <= 1 && left[0] == 1 && right[0] == 1) {
            b = 1;
        }

        return {b, height};
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }
};
