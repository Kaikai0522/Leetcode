class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        const int n = nums.size();
        int max_num = nums[0];
        for(int i = 1;i < n;++i) max_num |= nums[i];
        int ans = 0;
        backtracking(0, nums, 0, max_num, ans);
        return ans;
    }
    void backtracking(int cur, const vector<int>& nums, int index, int &max_num, int &ans){
        if(cur == max_num) {
            ans += 1 << (nums.size() - index);
            return;
        }
        if(index >= nums.size()) return;
        backtracking(cur, nums, index + 1, max_num, ans);
        backtracking(cur | nums[index], nums, index + 1, max_num, ans);
        return;
    }
};
