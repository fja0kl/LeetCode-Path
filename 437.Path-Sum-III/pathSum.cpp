/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * findPath函数用来计算从当前点出发，路径和等于给定值；
 * findPath完成树的遍历[先序遍历]
 *
 * pathSum 从每个点出发，计算等于给定值的路径和。
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return findPath(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }
private:
    int findPath(TreeNode* node, int sum){
        if(node == NULL)
            return 0;
        return (node->val == sum ? 1 : 0) + findPath(node->left,sum-node->val) + findPath(node->right, sum-node->val);
    }
};
