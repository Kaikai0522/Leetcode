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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *cur = head;
        int size = 0;
        while(cur != nullptr){ // calculate linklist's size
            ++size;
            cur = cur -> next;
        }
        vector<ListNode *> ans(k);
        int i = 0;
        cur = head;
        while(size > 0){
            int node_size = size / k + ((size % k > 0) ? 1 : 0); // size should the node has
            size -= node_size;
            --k;
            ans[i++] = make_linklist(&cur, node_size);
        }
        return ans;
    }
private:
    ListNode *make_linklist(ListNode **head, int size){ // use ListNode** to update original cur
        if(size <= 0) return nullptr; // this should never occur(unexpected)
        ListNode *new_head = new ListNode((*head) -> val), *cur = new_head;
        --size;
        (*head) = (*head) -> next;
        while(size--){
            ListNode *tmp = new ListNode((*head) -> val);
            (*head) = (*head) -> next;
            cur -> next = tmp;
            cur = cur -> next;
        }
        return new_head;
    }
};
