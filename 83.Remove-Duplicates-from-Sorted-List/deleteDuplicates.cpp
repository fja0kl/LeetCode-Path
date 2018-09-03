/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 真正删除多余的结点---删除占用内存位置
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* cur = head;
        
        while(cur!=NULL && cur->next!=NULL){
            if(cur->val == cur->next->val){
                ListNode* tmp = NULL;//
                tmp = cur->next;//
                cur->next = cur->next->next;
                delete tmp;//真正删除结点
            }
                
            else
                cur = cur->next;
        }
        return head;
    }
};
