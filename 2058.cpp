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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head -> next -> next == nullptr) return vector<int>(2, -1);
        ListNode* cur = head -> next;
        vector<int> ans(2, -1);
        bool first_time = true;
        int prev_i = 0, prev_val = head -> val, first_cri, i = 1;
        while(cur -> next != nullptr){
            int cur_val = cur -> val;
            if((cur -> next -> val > cur_val && prev_val > cur_val) ||
                (cur -> next -> val < cur_val && prev_val < cur_val)){
                if(first_time){
                    first_cri = i;
                    first_time = false;
                }
                else{
                    ans[1] = i - first_cri;
                    ans[0] = (ans[0] == -1) ? i - prev_i : min(ans[0], i - prev_i);
                }
                prev_i = i;
            }
            prev_val = cur_val;
            cur = cur -> next;
            ++i;
        }
        return ans;
    }
};
