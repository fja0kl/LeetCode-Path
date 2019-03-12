/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == nullptr || k <= 0) return nullptr;
        return KthNodeCore(pRoot, k);
    }
    TreeNode* KthNodeCore(TreeNode* pRoot, int& k){
        TreeNode* target = nullptr;//目标：第k个节点
        if (pRoot->left != nullptr)
            target = KthNodeCore(pRoot->left, k);
        if (target == nullptr){//没找到
            if (k == 1) target = pRoot;
            k--;
        }
        // 没找到
        if (target == nullptr && pRoot->right != nullptr)
            target = KthNodeCore(pRoot->right, k);
        
        return target;
    }
};
