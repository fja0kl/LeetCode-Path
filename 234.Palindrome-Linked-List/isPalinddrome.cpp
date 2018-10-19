/**
 * 感觉做法有点犯规：
 * 1. 遍历单链表，将元素值存储到数组里；
 * 2. 对数组进行判断，是否是回文数---对称比较
 *
 * 思考：O(n) Time; O(1) Space
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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* cur = head;
        while(cur){
            arr.push_back(cur->val);
            cur = cur->next;
        }
        int n = arr.size();
        for(int i=0;i<n/2;i++){
            if(arr[i] != arr[n-1-i])
                return false;
        }
        return true;
    }
};
