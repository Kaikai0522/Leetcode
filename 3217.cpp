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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> deletes(nums.begin(), nums.end());
        while(deletes.find(head -> val) != deletes.end()){
            head = head -> next;
            // add release node code here
        }
        ListNode* cur = head;
        while(cur -> next != nullptr){
            if(deletes.find(cur -> next -> val) != deletes.end())
                cur -> next = cur -> next -> next;
                // add release node code here
            else
                cur = cur -> next;
        }
        return head;
    }
};
