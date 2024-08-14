class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        while(left <= right){
            int mid = (left + right) / 2, cur_k = kth_smallest(mid, nums);
            if(cur_k < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
private:
    int kth_smallest(int max_distance, vector<int>& nums){
        const int n = nums.size();
        int left_i = 0, right_i = 1, cnt = 0, max_dis = INT_MIN;
        while(right_i < n){
            while(left_i < right_i && nums[right_i] - nums[left_i] > max_distance){
                ++left_i;
            }
            cnt += right_i - left_i;
            ++right_i;
        }
        return cnt;
    }
};
