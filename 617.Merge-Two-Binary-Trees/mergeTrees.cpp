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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1!= nullptr && t2!=nullptr){//t1 t2都不是空树
            TreeNode* root = new TreeNode(t1->val+t2->val);
            root->left = mergeTrees(t1->left,t2->left);//递归
            root->right = mergeTrees(t1->right,t2->right);
            
            return root;
        }
        
        return t1 == nullptr ? t2 : t1;//如果t1为空，返回t2，否则返回t1
    }
};
