/**
How it works:
This solution takes advantage of the fac thtat BST trees are already sorted where everything on your left is smaller than your root and everything on your right is larger.

I keep a global variable n as a counter to the kth number we want and ans for a return value.

In a helper function called inorder look into the left sides of the tree and when you hit a nullptr return.
After checking the left child (what would be your smaller element) check the right element.
Essentially travel as far as you can down the tree finding the smallest element and when you start unravelling the recursion start counting until you reach the kth smallest value. In this case I initialize the value of n with k and I'll decrement every time a recursion unravels until I get to 0 which means I've gotten to my kth smallest number. 

I check the left value first because it's smaller than the right, see if n is 0 to see if I got to the kth smallest yet, and then check the right side. In order you're always going to look at the leftmost side of the tree first and then work up the tree checking left, right, then the root which itself is a left child, then repeat checking the right and then the root.

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