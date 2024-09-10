/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */ 
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while(cur -> next != nullptr){
            int _gcd = gcd(cur->val, cur->next->val);
            ListNode *new_node = new ListNode(_gcd, cur -> next);
            cur -> next = new_node;
            cur = new_node -> next;
        }
        return head;
    }
};
