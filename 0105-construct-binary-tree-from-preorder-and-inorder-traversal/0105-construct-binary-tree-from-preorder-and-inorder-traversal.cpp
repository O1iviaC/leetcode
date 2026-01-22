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
    unordered_map<int, int> idx;
    int prePos = 0;

    TreeNode* build(vector<int>& preorder, int inL, int inR){
        if (inL > inR) return nullptr;

        int rootVal = preorder[prePos++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = idx[rootVal];
        root->left = build(preorder, inL, mid - 1);
        root->right = build(preorder, mid + 1, inR);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx.clear();
        prePos = 0;
        for(int i = 0 ; i  < inorder.size() ; i++){
            idx[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
        

    }
};