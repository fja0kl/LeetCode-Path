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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* first = new ListNode(-1);
        first->next = pHead;
        
        ListNode* pNode = pHead;
        ListNode* pPreNode = first;
        while (pNode != nullptr && pNode->next != nullptr){
            if (pNode->val == pNode->next->val){
                int val = pNode->val;
                while (pNode != nullptr && pNode->val == val)
                    pNode = pNode->next;
                pPreNode->next = pNode;
            } else{
                pPreNode = pNode;
                pNode = pNode->next;
            }
        }
        return first->next;
    }
};
