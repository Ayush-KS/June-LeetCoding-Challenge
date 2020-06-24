// Count Complete Tree Nodes

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};