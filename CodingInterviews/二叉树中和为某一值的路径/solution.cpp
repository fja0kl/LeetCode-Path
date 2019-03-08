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
        vector<vector<int>> result;
        if (root == nullptr) return result;
        vector<int> path;
        findPath(root, expectNumber, path, result);
        
        return result;
    }
    void findPath(TreeNode* root, 
                  int& expectNum, 
                  vector<int>& path,
                  vector<vector<int>>& res
  )
    {
        path.push_back(root->val);
        expectNum -= root->val;
        // 如果root是叶子节点，而且expectNum等于0，退出递归
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (expectNum == 0 && isLeaf){
            // 当前路径符合条件
            res.push_back(path);
            
            //return;
        }
        //如果不是叶子节点，遍历它的子树
        if (root->left)
            findPath(root->left, expectNum, path, res);
        if (root->right)
            findPath(root->right, expectNum, path, res);
        // 找到路径，或者找不到路径，复原:expectNum，以及path路径，弹出最后一个元素
        int top = path.back();
        path.pop_back();
        expectNum+= top;
    }
};
