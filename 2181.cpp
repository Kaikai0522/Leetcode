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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head -> next, *lastest = head, *prev = head;
int tmp = 0;
while(cur != nullptr){
    if(cur->val == 0){
        lastest -> val = tmp;
        prev = lastest;
        lastest = lastest -> next;
        tmp= 0;
    }
    else{
        tmp += cur->val;
    }
    cur = cur->next;
}
prev -> next = nullptr;
return head;
    }
};
