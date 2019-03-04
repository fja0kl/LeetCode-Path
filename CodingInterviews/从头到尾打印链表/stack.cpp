/**
* 栈：后进先出 or 先进后出
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        stack<ListNode*> s;
        ListNode* pNode = head;
        while (pNode != nullptr){
            s.push(pNode);
            pNode = pNode->next;
        }
        while (!s.empty()){
            ListNode* temp = s.top();
            res.push_back(temp->val);
            s.pop();
        }
        return res;
    }
};
