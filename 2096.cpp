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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        this->result = vector<string>();
        string tmp = "";
        findNode(root, startValue, tmp);
        findNode(root, destValue, tmp);
        int i = 0, n = min(result[0].size(), result[1].size());
        while(i < n && result[0][i] == result[1][i]) ++i;
        string ans(result[0].size() - i, 'U');
        ans += result[1].substr(i);
        return ans;
    }
private:
    void findNode(TreeNode *root, int target, string &res){
        if(root -> val == target){
            result.push_back(res);
            return;
        }
        if(root -> left != nullptr){
            res += "L";
            findNode(root -> left, target, res);
            res.pop_back();
        }
        if(root -> right != nullptr){
            res += "R";
            findNode(root -> right, target, res);
            res.pop_back();
        }
        return;
    }
    vector<string> result;
};
