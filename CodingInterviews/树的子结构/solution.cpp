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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        // 两个树都不为空
        if (pRoot1 != nullptr && pRoot2 != nullptr){
            //先判断当前pRoot1当前根与pRoot2值是否相等
            if (pRoot1->val == pRoot2->val)
                result = DoesTree1HaveTree2(pRoot1, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        // 返回result；result赋予初始值:如果判断失败，就是有空树，返回false；
        // 否则,返回运行结果 ps：空树不是任意一个树的子结构
        return result;
    }
    // 递归判断以pRoot1为根的树是否包含以pRoot2为根的树
    // 递归终止条件：到达了树A或树B的叶子节点
    bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        // 终止条件：
        // pRoot2遍历完，符合条件
        if (pRoot2 == nullptr) return true;
        // pRoo1遍历完，pRoot2还没有遍历完，不符合条件
        if (pRoot1 == nullptr) return false;
        // 中间结果，当前值不相等，返回false；
        if (pRoot1->val != pRoot2->val) return false;
        
        return DoesTree1HaveTree2(pRoot1->left, pRoot2->left)
            && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
    }
};
