/*
 * 递归形式
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorderTraverse(root, res);
        
        return res;
    }
    void preorderTraverse(Node* root, vector<int> &res){
        if(!root)
            return;
        res.push_back(root->val);
        for(int i=0;i<root->children.size();i++)
            preorderTraverse(root->children[i], res);
        
    }
};
