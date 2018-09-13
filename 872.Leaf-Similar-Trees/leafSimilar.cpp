/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return helper(root1) == helper(root2);
    }
    string helper(TreeNode* root){
        if (!root)
            return "";
        string res = "";
        if(!root->left && !root->right)
            return res+to_string(root->val);
        res += helper(root->left);
        res += helper(root->right);
        
        return res;
    }
};
