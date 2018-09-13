/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * v1,v2用来存储叶子结点的值；
 * 比较好的是：辅助函数不用返回值；直接填充到vector参数里；
 * 比我的更容易理解一点
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        vector<int> v1;
        vector<int> v2;
        helper(root1, v1);
        helper(root2, v2);
        return isSame(v1, v2);
        
    }
    
    void helper(TreeNode* root, vector<int>& v) {
        if(root == nullptr) return;
        if(!root->left && !root->right) {
            v.push_back(root->val);
        }
        helper(root->left, v);
        helper(root->right, v);
    }
    
    bool isSame(vector<int> v1, vector<int> v2) {
        if(v1.size() != v2.size()) return false;
        for(int i = 0; i < v2.size(); i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};
