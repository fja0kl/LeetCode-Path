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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if (pRoot == nullptr) return res;
            queue<TreeNode*> s;
            s.push(pRoot);
            while (!s.empty()){
                int size = s.size();
                vector<int> layer;
                while (size--){
                    TreeNode* head = s.front();
                    layer.push_back(head->val);
                    s.pop();
                    if (head->left) s.push(head->left);
                    if (head->right) s.push(head->right);
                }
                res.push_back(layer);
            }
            return res;
        }
    
};
