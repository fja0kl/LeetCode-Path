/**
 *
 * 层序遍历：循环实现；借助queue队列实现
 *
 * 主要限制是将每层的结果保存在一个vector数组里。
 *
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
        queue<TreeNode*> current, next;//current保存当前层结点；next保存下一层结点
        current.push(root);
        while(!current.empty()){
            vector<int> level;//保存某一层的结点
            while(!current.empty()){//遍历当前层结点
                TreeNode* node = current.front();
                current.pop();
                
                level.push_back(node->val);
                
                if(node->left) next.push(node->left);
                if(node->right) next.push(node->right);
            }//循环结束，current为空，next保留了所有的子节点
            res.push_back(level);//将当前层遍历结果push到最终结果里
            swap(current,next);//交换：current为下一层的所有子节点；next为空队列
        }
        return res;
    }

};
