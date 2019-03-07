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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        // 验证pListHead, k有效性
        if (pListHead == nullptr || k == 0) return nullptr;
        ListNode* pA = pListHead;
        ListNode* pB = nullptr;
        // pA指针先走k-1步，其中要判断k的有效性(过长)
        for (int i=0; i<k-1; i++){
            if (pA->next != nullptr)
                pA = pA->next;
            else// 超过当前链表长度，直接返回nullptr
                return nullptr;
        }
        pB = pListHead;
        // 同时移动pA，pB
        while (pA->next != nullptr){
            pA = pA->next;
            pB = pB->next;
        }
        return pB;
    }
};
