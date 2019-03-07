/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meetNode = meetingNode(pHead);
        if (meetNode == nullptr)//没有相遇
            return nullptr;
        // 计算环中节点数目
        int numOfNodesInKing = 1;
        ListNode* temp = meetNode->next;
        while (temp != meetNode){
            ++numOfNodesInKing;
            temp = temp->next;
        }
        ListNode* pA = pHead;
        ListNode* pB = pHead;
        // pA先走numOfNodesInKing，
        for (int i=0; i<numOfNodesInKing; i++)
            pA = pA->next;
        // 两个指针一块走，相遇时，找到环的入口
        while (pA != pB){
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
    ListNode* meetingNode(ListNode* pHead){
        if (pHead == nullptr) return nullptr;
        ListNode* pSlow = pHead;
        ListNode* pFast = pSlow->next;
        while (pSlow != nullptr && pFast != nullptr){
            if (pSlow == pFast)//不为空且相遇，说明存在环
                return pFast;
            // 慢指针走一步
            pSlow = pSlow->next;
            // 快指针走两步
            pFast = pFast->next;
            if (pFast != nullptr)
                pFast = pFast->next;
        }
        //在末尾相遇，不存在环
        return nullptr;
    }
};
