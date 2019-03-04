/**
* 头插法改进：最后翻转顺序。
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
            res.push_back(pNode->val);
            pNode = pNode->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
