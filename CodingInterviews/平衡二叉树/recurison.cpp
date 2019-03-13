class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == nullptr) return true;
        int left = getDepth(pRoot->left);
        int right = getDepth(pRoot->right);
        int depth = left - right;
        if (depth > 1 || depth < -1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    int getDepth(TreeNode* root){
        if (root == nullptr) return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        
        return max(left, right) + 1;
    }
};
