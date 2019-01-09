/**
 * 头结点的使用:
 * 新建一个头结点,使得所有操作都类似;删除,插入操作
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //新建一个头结点
        ListNode* dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        //开始swap交换相邻节点
        while(pre->next && pre->next->next){
            //交换两个相邻节点
            ListNode* t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            //更新pre指针;pre指针指向需要交换的第一个节点的前驱节点;类似于头结点的位置
            pre = t->next;
        }
        
        return dummy->next;
    }
};
