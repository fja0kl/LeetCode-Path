/**
 * 递归法
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
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
            return root;
        int sum = 0;
        Traverse(root, sum);
        
        return root;
    }
    
    void Traverse(TreeNode* root, int& sum){
        if(root == NULL)
            return;
        Traverse(root->right, sum);
        root->val += sum;
        sum = root->val;
        Traverse(root->left, sum);
    }
};
