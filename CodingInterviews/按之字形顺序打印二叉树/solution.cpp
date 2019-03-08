/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        if (pRoot == nullptr) return {};
        vector<vector<int>> result;
        stack<TreeNode*> levels[2];
        int cur = 0, next = 1;
        levels[cur].push(pRoot);
        
        vector<int> layer;
        while (!levels[0].empty() || !levels[1].empty()){
            TreeNode* temp = levels[cur].top();
            levels[cur].pop();
            
            layer.push_back(temp->val);
            // 奇数层入栈顺序：左右
            if (cur == 0){
                if (temp->left != nullptr)
                    levels[next].push(temp->left);
                if (temp->right != nullptr)
                    levels[next].push(temp->right);
            }
            else {//偶数层入栈顺序：右左
                if (temp->right != nullptr)
                    levels[next].push(temp->right);
                if (temp->left != nullptr)
                    levels[next].push(temp->left);
            }
            // 当前层访问结束，将cur，next颠倒
            if (levels[cur].empty()){
                cur = 1- cur;
                next = 1 - next;
                result.push_back(layer);
                layer.clear();
            }
        }
        return result;
    }
    
};
