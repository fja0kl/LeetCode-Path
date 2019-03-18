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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == nullptr) return {};
        vector<vector<int>> result;
        vector<int> path;
        findPath(root, expectNumber, result, path);
        
        return result;
    }
    //本质上是一个先序遍历：根左右
    void findPath(TreeNode* root, int expectNumb, vector<vector<int>>& result,
                 vector<int>& path){
        path.push_back(root->val);
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (expectNumb == root->val && isLeaf){
            result.push_back(path);
            /**
            * return: 加上return 会出错；遍历到root的右分支时左分支的节点还在
            * path里，导致路径出错。
            **/
        }
        //要保证root不为空；因为第一次调用时，在外函数中已经保证，重新调用时，需要验证
        if(root->left) findPath(root->left, expectNumb-root->val, result, path);
        if(root->right) findPath(root->right, expectNumb-root->val, result, path);
        // 遍历完一个小分支，对先前加入的元素进行弹出
        // 可以保证和调用函数之前的path保持一致
        // 不用对expectNumb进行还原，因为是值传递，并不影响之前的调用
        path.pop_back();
        // 最后进行return
        return;
    }
};
