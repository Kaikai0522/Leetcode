class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        const int n = nums.size();
        int left = 0, right = 0, ans = 1;
        multiset<int> history = {nums[0]};
        while(left <= right && (right + 1) < n){
            ++right;
            history.insert(nums[right]);
            while(*history.rbegin() - *history.begin() > limit){
                history.erase(history.find(nums[left]));
                ++left;
            }
            ans = max(ans, (int)history.size());
        }
        return ans;
    }
};
