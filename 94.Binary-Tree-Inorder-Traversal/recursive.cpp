/**
 *
 * 递归法：需要一个辅助函数，因为树的遍历算法一般是没有输出的，所以需要一个引用类型的参数，可以直接修改.
 *
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        inorder(root, res);
        
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int> & res){
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};
