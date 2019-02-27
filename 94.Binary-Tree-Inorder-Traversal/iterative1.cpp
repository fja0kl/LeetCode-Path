/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 用数组代替stack使用；
 * cur 不为空：判断cur是否为null： if(cur){不为空}；如果不清楚if(cur != null)
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty()){
            while (cur){
                s.push_back(cur);
                cur = cur->left;
            }
            cur = s.back();
            s.pop_back();
            res.push_back(cur->val);
            cur = cur->right;
        }
        
        return res;
    }

};
