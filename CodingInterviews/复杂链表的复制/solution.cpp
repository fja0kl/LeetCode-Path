/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        cloneNodes(pHead);
        cloneRandomPtr(pHead);
        return seperate(pHead);
    }
    // 赋值节点：主要链接next指针
    void cloneNodes(RandomListNode* pHead){
        //if (pHead == nullptr) return;
        RandomListNode* pNode = pHead;
        while (pNode != nullptr){
            RandomListNode* pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next;
            pNode->next = pCloned;
            // 更新指针
            pNode = pCloned->next;
        }
    }
    // 赋值节点： 主要链接random指针
    void cloneRandomPtr(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while (pNode != nullptr){
            RandomListNode* pCloned = pNode->next;
            if (pNode->random != nullptr)
                pCloned->random = pNode->random->next;
            // 更新pNode指针
            pNode = pCloned->next;
        }
    }
    // 完成next和random指针链接后，将原始链表和复制链表分离
    // 主要修改next指针
    RandomListNode* seperate(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = nullptr;
        RandomListNode* pClonedNode = nullptr;
        if (pNode != nullptr){//先对复制链表变量赋值
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        while (pNode != nullptr){
            /* 出错原因在于：pNode为空，pNode->next不存在，调用出错；
            eg：指向倒数第二个节点：前两步更新完，pNode为空，更新pClonedNode
            next指针出错；先更新一次pNode，放在上面
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
            pClonedNode->next = pNode->next;
            pClonedNode = pNode->next;
            */
            //更新pClonedNode
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            // 更新pNode
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        
        return pClonedHead;
    }
};
