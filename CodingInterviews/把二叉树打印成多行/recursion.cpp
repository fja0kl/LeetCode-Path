/*
先把存储结构定义好，然后往数组中插值。
[存储结构新定义时，要注意定义条件---满足什么条件时，定义新结构；不要重复定义]


不用每次重新声明变量。

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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        layerTraverse(pRoot, result, 1);
        
        return result;
    }
    void layerTraverse(TreeNode* pRoot, vector<vector<int>>& result, int height){
        if (pRoot == nullptr) return;
        if (height > result.size()){//依据层数，进行添加新vector数组
            result.push_back(vector<int>{});
        }
        result[height-1].push_back(pRoot->val);
        layerTraverse(pRoot->left, result, height+1);
        layerTraverse(pRoot->right, result, height+1);
    }
};
