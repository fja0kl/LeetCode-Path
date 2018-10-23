/**
 *
 * 通过自己定义一个用户栈实现；
 *
 * 递归法：系统会声明一个系统栈，使用系统栈
 *
 * 无论是递归法还是循环法，都需要借助栈。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != nullptr || !s.empty()){
            while(cur != nullptr){//向左走，直到叶子结点
                s.push(cur);
                cur = cur->left;
            }
            //遍历到叶子结点后，栈弹出，访问这个结点；然后对右子树进行遍历
            TreeNode* tmp = s.top();
            s.pop();
            res.push_back(tmp->val);
            cur = tmp->right;
        }
        
        return res;
    }
};
