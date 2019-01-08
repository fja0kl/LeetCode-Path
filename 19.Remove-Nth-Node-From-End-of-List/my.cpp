/**
 * 由于单链表的单向性以及不可直达性,设计一个辅助函数getLength,先获取list的长度,然后确定导数第n个元素的前驱节点,然后直接删除即可;
 * 有一个要注意的点是:如果倒数第n个点正好是第一个点,也就是头结点,处理方式有一点不同,要区分开来
 *
 *
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int idx = getLength(head) - n - 1;
        ListNode* temp = head;
        while(idx>0){
            temp = temp->next;
            idx--;
        }
        if(idx == -1){
            head = head->next;
            return head;
        }
        ListNode* p = temp->next;
        temp->next = p->next;
        delete p;
        
        return head;
    }
private:
    int getLength(ListNode* head){
        int length = 0;
        while(head){
            length++;
            head = head->next;
        }
        return length;
    }
};
