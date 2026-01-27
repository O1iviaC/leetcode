/**
If subRoot is null it's always a subTree of root but if root is null and subRoot isn't then subRoot isn't a subtree.

DFS method:
After checking this edge case see if the tree is the same as the subtree given based on the current node you're looking at. If they aren't the same, keep searching the left and right of that node.

Within sameTree we're comparing nodes in tree a with nodes in tree b to see if they're the same so we can't have that one is a nullptr and the other isn't and we can't have that they're different values so return false for either of those scenarios. If they're not nullptrs and they're of equal value continue looking at the left children and right children to make sure they're correct and repeat until you get to the ends of the trees. (nullptr)

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
    bool sameTree(TreeNode* a, TreeNode* b){
        if(a == nullptr && b == nullptr) return true;
        if(a == nullptr || b == nullptr)return false;
        if (a->val != b->val) return false;

        return sameTree(a->left, b->left) && sameTree(a->right, b->right);
        }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;

        if(sameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};