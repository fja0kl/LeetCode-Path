/**
 * 双指针(快慢指针): 查找第n个节点;
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //快慢指针,快慢指针来寻找第n个点
        ListNode* fast = head, *slow = head;
        for(int i=0; i<n; i++)
            fast = fast->next;
        //判断是否到了末尾null,也就是判断倒数第n个点是不是头结点
        if(fast == NULL)
            return head->next;
        //快慢指针移动,指向导数第n个点
        //fast指向末尾节点时,slow指向导数第n个点的前驱节点
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        //删除倒数第n个节点
        slow->next = slow->next->next;
        
        return head;
    }
};
