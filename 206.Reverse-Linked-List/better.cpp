/**
 * 逐个元素翻转；
 * 时间复杂度O(n)；空间复杂度O(1).
 *
 * !Good!
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode* cur = head->next;//处理的当前结点
        ListNode* pre = head;//翻转后子链表的头
        head->next = NULL;//尾结点next设置为NULL
        
        ListNode* tmp = NULL;
        while(cur){
            tmp = cur->next;//保存当前结点的后续结点
            cur->next = pre;//翻转处理，将当前结点指向前一结点，逐个翻转
            pre = cur;//更新
            cur = tmp;
        }
        
        head = pre;//遍历结束后，cur指向NULL；pre指向原来的尾结点；更新head
        
        return head;
    }
};
