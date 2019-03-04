/**
 * 递归方法
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || vin.empty() || pre.size() != vin.size()) return nullptr;
        int length = pre.size();
        // 分别存储前序遍历，中序遍历以根节点划分的两半部分
        vector<int> leftPre, rightPre, leftIn, rightIn;
        // 查找根元素在中序遍历的位置，方便划分pre，vin数组
        int rootIn = 0;//同时等于左半部分数组的长度
        while (rootIn < length){
            if (vin[rootIn] == pre[0])
                break;
            rootIn++;
        }
        TreeNode* root = new TreeNode(pre[0]);
        // 划分pre和vin
        for (int i=0; i<rootIn; i++){
            leftPre.push_back(pre[i+1]);
            leftIn.push_back(vin[i]);
        }
        for (int i=rootIn+1; i<length; i++){
            rightPre.push_back(pre[i]);
            rightIn.push_back(vin[i]);
        }
        // 递归创建左右子树
        root->left = reConstructBinaryTree(leftPre, leftIn);
        root->right = reConstructBinaryTree(rightPre, rightIn);
        
        return root;
    }
};
