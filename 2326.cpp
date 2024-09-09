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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int x = 0, y = 0, dir_i = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(head != nullptr){
            res[x][y] = head->val;
            head = head->next;
            int tmp_x = x + dir[dir_i][0], tmp_y = y + dir[dir_i][1];
            if(tmp_x >= m || tmp_x < 0 || tmp_y >= n || tmp_y < 0 || res[tmp_x][tmp_y] != -1){
                dir_i = (dir_i + 1) % 4;
            }
            x += dir[dir_i][0];
            y += dir[dir_i][1];
        }
        return res;
    }
};
