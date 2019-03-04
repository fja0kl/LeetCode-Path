/**
* 递归
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
    vector<int> res;
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head != nullptr){
            if (head->next != nullptr)
                res = printListFromTailToHead(head->next);
            res.push_back(head->val);
        }
        return res;
    }
};
