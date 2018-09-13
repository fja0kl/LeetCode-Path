class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        
        TreeNode *root = new TreeNode(0);//0
        
        if (t1) root->val += t1->val;//直接加
        if (t2) root->val += t2->val;
        
        root->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        root->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        
        return root;
    }
};
