/*

递归解决。


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 处理鲁棒性问题：异常值
        if (pHead1 == nullptr) return pHead2;
        else if (pHead2 == nullptr) return pHead1;
        // 其他情况，进行合并
        ListNode* pMergedHead = nullptr;
        if (pHead1->val < pHead2->val){
            pMergedHead = pHead1;
            pMergedHead->next = Merge(pHead1->next, pHead2);
        } else {
            pMergedHead = pHead2;
            pMergedHead->next = Merge(pHead1, pHead2->next);
        }
        return pMergedHead;
    }
};
