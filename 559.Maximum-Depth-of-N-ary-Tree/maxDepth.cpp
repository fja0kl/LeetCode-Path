/*
 * 和二叉树的最大深度解法相同
 *
 * vector<int> 求最大值，并不好弄
 *
 * max(a,b):只能求两个数之间的最大值
 *
 *
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
    int maxDepth(Node* root) {
        if(!root) return 0;
        
        int maxDep = 0;
        for(int i=0;i<root->children.size();i++)
            maxDep = max(maxDep, maxDepth(root->children[i]));
        return 1 + maxDep;
    }
};
