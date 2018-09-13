/**
 * Definition for a binary tree node.
 * struct TreeNode {//结点结构定义
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 *
 * 主要思路：因为树的定义是递归定义的；最简单的实现方法是采用递归方法。
 * 
 * 辅助函数
 * helper命名
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums,int left, int right){
        if(left>right)
            return NULL;
        int maxIndex = left;
        for(int i=left;i<=right;i++)//用来查找最大值的下标
            if(nums[i]>nums[maxIndex])
                maxIndex = i;
        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = helper(nums,left,maxIndex-1);//递归实现
        root->right = helper(nums,maxIndex+1,right);
        
        return root;
    }
};
