/**
 * 单链表：快慢指针
 * 首先考虑：链表是否为空？
 * 不为空，接着操作！
 * !空! 
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL||head->next==NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){//判断条件：主要因为不能对空间点的下一个结点操作--出错！ 确保fast、fast->next不为空		
            slow = slow->next;//一步
            fast = fast->next->next;//两步
            if(slow == fast)
                return true;
        }
        return false;
    }
};
