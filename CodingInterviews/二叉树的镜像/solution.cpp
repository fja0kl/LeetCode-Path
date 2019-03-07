/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        // 异常值处理
        if (pRoot == nullptr) return;
        // 终止条件：到了叶子节点
        if (pRoot->left == nullptr && pRoot->right == nullptr) return;
        // 非叶子节点，交换当前节点的左右孩子
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        // 递归调用交换左右子树
        if (pRoot->left)//不为空，进行交换
            Mirror(pRoot->left);
        if (pRoot->right)
            Mirror(pRoot->right);
    }
};
