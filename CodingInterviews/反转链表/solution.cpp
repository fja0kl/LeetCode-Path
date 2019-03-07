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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pReversedHead = nullptr;
        ListNode* pNode = pHead;
        ListNode* pPre = nullptr;
        while (pNode != nullptr){
            // 先保留当前节点的原来向后指向
            ListNode* pNext = pNode->next;
            if (pNode->next == nullptr)//处理到原来链表末尾，也就是翻转后的头结点
                pReversedHead = pNode;
            // 翻转当前节点的指向，指向前面的节点
            pNode->next = pPre;
            // 更新循环指针
            pPre = pNode;
            pNode = pNext;
        }
        // 如果pHead为nullptr，返回nullptr；其他情况，返回翻转后的表头；
        // 将nullptr赋值给翻转后的表头，两个过程统一起来，通过循环条件判断两个过程
        return pReversedHead;
    }
};
