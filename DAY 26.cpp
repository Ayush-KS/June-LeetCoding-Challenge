// Sum Root to Leaf Numbers

class Solution {
public:
    int helper(TreeNode* root, int curr) {
        if(!root)
            return 0;
        if(!root -> left && !root -> right) {
            return (curr*10 + root -> val);
        }
        int ans = 0;
        if(root -> left) {
            ans += helper(root -> left, (curr*10 + root -> val));
        }
        if(root -> right) {
            ans += helper(root -> right, (curr*10 + root -> val));
        }
        return ans;
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        return helper(root, 0);
    }
};