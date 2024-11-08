class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int n = nums.size();
        vector<int> ans(n);
        int cur_ans = nums[0];
        for(int i = 1;i < n;++i)
            cur_ans ^= nums[i];
        cur_ans ^= ((int)pow(2, maximumBit) - 1);
        ans[0] = cur_ans;
        for(int i = n - 1;i > 0;--i){
            cur_ans ^= nums[i];
            ans[n - i] = cur_ans;
        }
        return ans;
    }
};
