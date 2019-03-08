/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> result;
        layerTraverse(root, result);
        
        return result;
    }
    void layerTraverse(TreeNode* root, vector<int>& result){
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* temp = q.front();
            result.push_back(temp->val);
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
};
