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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        convert(pRootOfTree, pre);
        while (pre != nullptr && pre->left != nullptr)
            pre = pre->left;
        return pre;
    }
    void convert(TreeNode* pRoot, TreeNode*& pre){
        if (pRoot == nullptr) return;
        // pre指向双向链表的末尾
        convert(pRoot->left, pre);
        pRoot->left = pre;
        if (pre != nullptr) pre->right = pRoot;
        pre = pRoot;
        convert(pRoot->right, pre);
    }
};
