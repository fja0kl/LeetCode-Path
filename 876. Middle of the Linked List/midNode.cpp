/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 还是只有头指针，没有头结点
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head ==NULL)
            return head;
        int length = getLength(head);
        int mid = length/2;
        ListNode* cur = head;
        for(int i=0;i<mid;i++){
            //if(cur!=NULL && cur->next!=NULL)
            cur = cur->next;
        }
        return cur;
    }
    
    int getLength(ListNode* head){//实现：不带头结点，头指针
        ListNode* p = head;
        int len = 0;
        while(p){
            len++;
            p = p->next;
        }
        return len;
    }
};
