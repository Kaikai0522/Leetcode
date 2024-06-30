class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        queue<int> left_even;
        int odd = 0, even = 0, ans = 0;
        for(int i = 0;i < n;++i){
            if(nums[i] & 1){
                ++odd;
                left_even.push(even);
                if(odd == k + 1){
                    ans += (even + 1) * (left_even.front() + 1);
                    left_even.pop();
                    --odd;
                }
                even = 0;
            }
            else ++even;
        }
        if(left_even.size() > 0 && odd == k)
            ans += (even + 1) * (left_even.front() + 1);
        return ans;
    }
};
