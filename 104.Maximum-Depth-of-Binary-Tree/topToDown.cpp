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
    int maxDepth(TreeNode* root) {
        int answer = 0;
        findMaxDepth(root, 1, answer);
        
        return answer;
    }
private:
    void findMaxDepth(TreeNode* root, int level, int& answer){
        if (!root) return;
        if (!root->left && !root->right)
            answer = max(answer, level);
        
        findMaxDepth(root->left, level+1, answer);
        findMaxDepth(root->right, level+1, answer);
    }
};
