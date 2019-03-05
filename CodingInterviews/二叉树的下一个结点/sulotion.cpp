/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == nullptr) return nullptr;
        // 返回值
        TreeLinkNode* pNext = nullptr;
        // Occa 1: 右子树不为空
        if (pNode->right != nullptr){
            TreeLinkNode * pRight = pNode->right;
            // 右子树的最左节点
            while (pRight->left != nullptr)
                pRight = pRight->left;
            pNext = pRight;
        } else if (pNode->next != nullptr){//父亲节点不为空
            TreeLinkNode* pCur = pNode;
            TreeLinkNode* pParent = pNode->next;
            //Occa 2: 右子树为空，且是父亲节点的右子节点
            // 向上递归，直到节点是父亲节点的左节点，返回父亲节点；
            while (pParent != nullptr && pCur == pParent->right){
                pCur = pParent;
                pParent = pParent->next;
            }
            //Occa 3: 右子树为空，且是父亲节点的左节点，直接返回父亲节点；
            //Occa 2：直到父亲节点；
            // 共享的
            pNext = pParent;// 父亲结点不为空，右子树为空(最后一个结点)--nullptr
        }
        return pNext;
    }
};
