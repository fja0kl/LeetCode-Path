/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 对preorder做变形：变成 根-右-左，然后再对结果做一次翻转，得到最终的左-右-根
 * preorder: 根-左-右；postorder：左-右-根；
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> s;
        TreeNode* cur = root;
        
        while (!s.empty() || cur){
            if (cur){
                s.push_back(cur);
                res.insert(res.begin(), cur->val);
                cur = cur->right;
            } else {
                cur = s.back();
                s.pop_back();
                cur = cur->left;
            }
        }
        
        return res;
    }

};
