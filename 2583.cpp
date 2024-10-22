/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> level_sums;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int _size = q.size();
            long long sum = 0;
            while(_size--){
                TreeNode *cur = q.front();
                q.pop();
                sum += cur -> val;
                if(cur -> left != nullptr) q.push(cur -> left);
                if(cur -> right != nullptr) q.push(cur -> right);
            }
            level_sums.push_back(sum);
        }
        sort(level_sums.begin(), level_sums.end(), [](const long long &a, const long long &b){return a > b;});
        if(level_sums.size() < k) return -1;
        return level_sums[k - 1];
    }
};
