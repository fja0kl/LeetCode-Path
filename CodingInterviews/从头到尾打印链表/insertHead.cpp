/**
* 头插法：效率低。
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
        if (head == nullptr) return res;
        ListNode* pNode = head;
        while (pNode != nullptr){
            res.insert(res.begin(), pNode->val);
            pNode = pNode->next;
        }
        return res;
    }
};
