/**
 * if root = null, return null
 * if root.val < L, root and its left subtree are to remove, the problem is decreased to trimBST rooted at root.right
 * if root.val > R, root and its right subtree are to remove, the problem is decreased to trimBST rooted at root.left
 * if L <= root.val <= R, root remains, the problem is decreased to trimBST rooted at root.left,  trimBST rooted at root.right, and append new subtree roots to root.
 *
 */


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
            return root;
        if(root->val < L)
            return trimBST(root->right,L,R);
        if(root->val > R)
            return trimBST(root->left,L,R);
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
        
        return root;
    }
};
