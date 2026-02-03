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

    int n;
    int ans;

    void inorder(TreeNode* node) {
        if (node == nullptr) return;

        inorder(node->left);

        // visit this node
        n--;
        if (n == 0) {
            ans = node->val;
            return; // we found it
        }

        inorder(node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        n = k;
        inorder(root);
        return ans;
    }
};