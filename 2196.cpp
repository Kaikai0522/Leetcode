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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        const int n = descriptions.size();
        unordered_map<int, TreeNode*> hash;
        unordered_set<int> is_root;
        hash.reserve(n);
        is_root.reserve(n);
        for(int i = 0;i < n;++i)
            is_root.insert(descriptions[i][0]);
            
        for(int i = 0;i < n;++i){
            if(hash.count(descriptions[i][0]) == 0){ //if cur node isn't exist
                TreeNode* cur = new TreeNode(descriptions[i][0]);
                hash[descriptions[i][0]] = cur;
            }
            if(hash.count(descriptions[i][1]) == 0){ //if left node isn't exist
                TreeNode *new_left = new TreeNode(descriptions[i][1]);
                hash[descriptions[i][1]] = new_left;
            }
            if(descriptions[i][2]) // is left
                hash[descriptions[i][0]] -> left = hash[descriptions[i][1]];
            else
                hash[descriptions[i][0]] -> right = hash[descriptions[i][1]];
            is_root.erase(descriptions[i][1]);
        }
        return hash[*is_root.begin()];
    }
};
auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();
