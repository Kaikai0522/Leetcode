class Solution {
public:
    int minSwaps(vector<int>& nums) {
        const int n = nums.size();
        int one_cnt = 0;
        for(int i = 0;i < n;++i){
            if(nums[i] == 1) ++one_cnt;
        }
        int left = 1, right = one_cnt, cur_one_cnt = 0, ans;
        for(int i = 0;i < one_cnt;++i){
            if(nums[i] == 1) ++cur_one_cnt;
        }
        ans = one_cnt - cur_one_cnt;
        for(int i = 1;i < n;++i, ++left, right = (right + 1) % n){
            if(nums[left - 1] == 1) --cur_one_cnt;
            if(nums[right] == 1) ++cur_one_cnt;
            ans = min(ans, one_cnt - cur_one_cnt);
        }
        return ans;
    }
};
