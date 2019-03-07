
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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == nullptr) return true;
        return isSymmetrical(pRoot->left, pRoot->right);
    }
    bool isSymmetrical(TreeNode* root1, TreeNode* root2){
	// 终止条件
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        if (root1->val != root2->val) return false;
        
	return isSymmetrical(root1->left, root2->right) &&
            isSymmetrical(root1->right, root2->left);
    }

};
