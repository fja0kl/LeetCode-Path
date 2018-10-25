/**
 * 层序遍历：递归实现
 *
 * 非递归实现：需要借助队列实现
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) return res;
        leveltraverse(root, 1, res);
        
        return res;
    }
private:
    void leveltraverse(TreeNode* root, int level, vector<vector<int> >& res){
        if(!root) return;
        if(level > res.size())
            res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        leveltraverse(root->left, level+1, res);
        leveltraverse(root->right, level+1, res);
    }
};
