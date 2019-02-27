/**
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
        vector<vector<int>> res;
        levelorder(root, 0, res);
        
        return res;
    }
private:
    void levelorder(TreeNode* root, int level, vector<vector<int>>& res){
        if (root == nullptr) return;
        // 创建新vector容器，装载下一层的数据
        if (level == res.size()) res.push_back(vector<int>());
        
        res[level].push_back(root->val);
        levelorder(root->left, level+1, res);
        levelorder(root->right, level+1, res);
    }
};
