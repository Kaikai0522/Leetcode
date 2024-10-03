class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int n = nums.size();
        unordered_map<int, int> remainder_index;
        remainder_index[0] = -1;
        int remainder = 0;
        for(int i = 0;i < n;++i){
            remainder = (remainder + nums[i]) % p;
        }
        if(remainder == 0) return 0;
        int ans = n, prefix_sum = 0;
        for(int i = 0;i < n;++i){
            prefix_sum += nums[i];
            prefix_sum %= p;
            auto it = remainder_index.find((prefix_sum - remainder + p) % p);
            if(it != remainder_index.end()){
                ans = min(ans, i - it->second);
            }
            remainder_index[prefix_sum] = i;
        }
        if(ans == n) return -1;
        return ans;
    }
};
