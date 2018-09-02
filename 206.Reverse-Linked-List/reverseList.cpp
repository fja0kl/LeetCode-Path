/**
 * 翻转单链表
 * 头插法,尾插法
 * 头插法可以实现
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)//还是写全比较好
            return head;
        ListNode* res = new ListNode(-1);
        ListNode* cur = head;
        while(cur){
            ListNode* temp = new ListNode(cur->val);
            temp->next = res->next;
            res->next = temp;
            cur = cur->next;
        }
        return res->next;//带头结点，返回第一结点开头的链表
    }
};
