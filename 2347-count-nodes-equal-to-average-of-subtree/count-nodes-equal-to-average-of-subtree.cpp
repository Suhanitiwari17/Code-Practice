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
    int sum(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = sum(root->left);
        int right = sum(root->right);

        return root->val + left + right;
    }

    int count(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = count(root->left);
        int right = count(root->right);

        return 1 + left + right;
    }

    int solve(TreeNode* root) {
        if (root == nullptr) return 0;

        int ans = 0;

        int total = sum(root);
        int nodes = count(root);

        int avg = total / nodes;

        if (root->val == avg) {
            ans++;
        }

        ans += solve(root->left);
        ans += solve(root->right);

        return ans;
    }

    int averageOfSubtree(TreeNode* root) {
        return solve(root);
    }
};