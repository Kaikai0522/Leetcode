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
    TreeNode* balanceBST(TreeNode* root) {
        visit_all(root);
        TreeNode* new_root = nullptr;
        new_root = create_blance_tree(0, nums.size() - 1);
        return new_root;
    }
private:
    TreeNode* create_blance_tree(int left, int right){
        if(left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root =  new TreeNode(nums[mid]);
        root->left = create_blance_tree(left, mid - 1);
        root->right = create_blance_tree(mid + 1, right);
        return root;
    }
    void visit_all(TreeNode* root){
        if(root->left != nullptr)
            visit_all(root->left);
        nums.push_back(root->val);
        if(root->right != nullptr)
            visit_all(root->right);
    }
    vector<int> nums;
};
