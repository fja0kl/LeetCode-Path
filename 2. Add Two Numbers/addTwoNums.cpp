/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 * 单链表：头结点
 * 插入、指针、遍历[cur指针，注意指针的更新]
 * 三元操作符
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);//头结点
        ListNode* cur = res;//用来对res列表遍历，添加新节点
        int carray = 0;//进位
        while(l1||l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carray;
            carray = sum / 10;
            ListNode* temp = new ListNode(sum%10);
            cur->next = temp;//新节点添加到res
            cur = cur->next;//更新指向新添加节点；保证永远指向末尾；
            if(l1) l1 = l1->next;//非空时，更新
            if(l2) l2 = l2->next;
        }
        if(carray)// 最高位进位
            cur->next = new ListNode(1);
        return res->next;
    }
};
