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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return helper(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }
private:
    int helper(TreeNode* node, int sum){
        if(node == NULL)
            return 0;
        return (node->val == sum ? 1 : 0) + helper(node->left,sum-node->val) + helper(node->right, sum-node->val);
    }
};
