/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 没有链表？只给了要删除的结点
 * 将后一个结点的值覆盖到这个节点上，下一个结点没有指针指向，成了一个独立结点
 * 但结点没有删除
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
//         ListNode* pre = head;
//         ListNode* cur = head;
        
//         while(cur!=NULL&&cur->val!=node->val){
//             pre = cur;
//             cur = cur->next;
//         }
//         //结点都是有效的；省去判断
//         pre->next = cur->next;
//         delete cur;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
