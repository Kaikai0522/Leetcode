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
    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        getPairs(root, distance);
        return ans;
    }
private:
    vector<int> getPairs(TreeNode* root, int &distance){
        if(root == nullptr) return vector<int>();
        if(root -> left == nullptr && root -> right == nullptr){
            vector<int> tmp(11, 0);
            tmp[1] ++;
            return tmp;
        }
        vector<int> left_res(0), right_res(0), res(11);
        left_res = getPairs(root -> left, distance);
        right_res = getPairs(root -> right, distance);
        if(left_res.size() && right_res.size()){
            for(int i = 1;i < distance;++i){
                for(int j  = 1;j <= distance - i;++j){
                    if(left_res[i] > 0 && right_res[j] > 0)
                        ans += left_res[i] * right_res[j];
                }
            }
            for(int i = 1;i < 10;++i)
                res[i + 1] = left_res[i] + right_res[i];
            res[1] = 0;
        }
        else if(left_res.size()){
            for(int i = 10;i > 1;--i)
                res[i] = left_res[i - 1];
            res[1] = 0;
        }
        else if(right_res.size()){
            for(int i = 10;i > 1;--i)
                res[i] = right_res[i - 1];
            res[1] = 0;
        }
        return res;
    }
    int ans;
};
