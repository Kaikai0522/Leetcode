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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        const unordered_set<int> to_del(to_delete.begin(), to_delete.end());
        TreeNode* tmp;
        if((tmp = visit_all_node(root, to_del, ans)) != nullptr)
            ans.push_back(tmp);
        return ans;
    }
private:
    TreeNode* visit_all_node(TreeNode* root, const unordered_set<int>& to_del, vector<TreeNode*> &ans){
        if(root -> left != nullptr)
            root -> left = visit_all_node(root -> left, to_del, ans);
        if(root -> right != nullptr)
            root -> right = visit_all_node(root -> right, to_del, ans);
        if(to_del.find(root -> val) != to_del.end()){
            if(root -> left != nullptr)
                ans.push_back(root -> left);
            if(root -> right != nullptr)
                ans.push_back(root -> right);
            return nullptr;
        }
        return root;
    }
};
