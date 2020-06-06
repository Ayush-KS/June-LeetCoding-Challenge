// Invert Binary Tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* tempLeft = root -> left;
        root -> left = invertTree(root -> right);
        root -> right = invertTree(tempLeft);
        return root;
    }
};
