/**
 * 将树的叶子结点间的距离保存起来，最后找最大值；
 * 可以将找最大值和求树的最大深度结合起来，减少复杂度
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
    vector<int> depths;
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        int maxLen = 0;
        for(auto i: depths){
            maxLen = max(maxLen, i);
        }
        return maxLen;
    }
    int getDepth(TreeNode* root){
        if(!root) 
            return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        depths.push_back(left+right);
        
        return max(left+1,right+1);
    }
};
