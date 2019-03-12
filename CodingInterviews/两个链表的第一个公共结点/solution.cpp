/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);
        int lenDiff = len1 - len2;
        // 生命新节点，方便遍历链表
        ListNode* pLong = pHead1;
        ListNode* pShort = pHead2;
        // 确保指针指向正确
        if (len2 > len1){
            pLong = pHead2;
            pShort = pHead1;
            lenDiff = len2 - len1;
        }
        // 长链表先移动
        for (int i=0; i< lenDiff; i++)
            pLong = pLong->next;
        // 同时移动
        while (pLong != nullptr && pShort != nullptr && pLong != pShort){
            pLong = pLong->next;
            pShort = pShort->next;
        }
        ListNode* pTarget = pLong;
        
        return pTarget;
    }
    int getLength(ListNode* root){
        int length = 0;
        ListNode* pNode = root;
        while (pNode != nullptr){
            ++length;
            pNode = pNode->next;
        }
        return length;
    }
};
