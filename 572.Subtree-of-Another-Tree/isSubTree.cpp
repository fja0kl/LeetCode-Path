/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * 一个辅助函数：判断两棵树是否相等；
 *
 * 
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s || !t) return false;
        // 先看当前结点两个树是否相等，否->看s的子树(对s树进行了遍历)
        return isSame(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
private:
    bool isSame(TreeNode* a, TreeNode* b){
        if(!a && !b)
            return true;
        
        if(a && b)
            return (a->val == b->val) && isSame(a->left,b->left) && isSame(a->right,b->right);
        
        return false;
    }
};
