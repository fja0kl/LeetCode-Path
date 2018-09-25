/**
 * 辅助函数：获取list长度；交点之后，都相等；不会再分叉
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int Alen = getListLength(headA);
        int Blen = getListLength(headB);
        
        int sub = Alen - Blen;
        ListNode* list1 = headA, *list2 = headB;
        
        for(int i=0;i<abs(sub);i++){
            if(sub > 0) list1 = list1->next;
            else list2 = list2->next;
        }
        
        while(list1 && list2){
            if(list1 == list2)
                return list1;
            list1 = list1->next;
            list2 = list2->next;
        }
        return NULL;
    }
    int getListLength(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
};
