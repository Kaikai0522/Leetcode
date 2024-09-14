class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        int max_length = 1, max_num = -1, length;
        for(int i = 0;i <n;++i){
            if(nums[i] > max_num){
                max_length = length = 1;
                max_num = nums[i];
            }
            else if(nums[i] == max_num){
                ++length;
                max_length = max(length, max_length);
            }
            else length = 0;
        }
        return max_length;
    }
};
