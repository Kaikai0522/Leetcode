class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        int len = 1;
        while(len <= n){
            int sum = 0;
            for(int i = 0;i < len;++i){
                sum += nums[i];
            }
            sums.push_back(sum);
            int left = 0, right = len;
            for(;right < n;++left, ++right){
                sum -= nums[left];
                sum += nums[right];
                sums.push_back(sum);
            }
            ++len;
        }
        sort(sums.begin(), sums.end());
        int ans = 0;
        for(int i = left - 1;i < right;++i){
            ans += sums[i];
            ans %= ((int)1e9 + 7);
        }
        return ans;
    }
};
