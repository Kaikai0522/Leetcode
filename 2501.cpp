#define MAX_NUM ceil(pow(INT_MAX, 0.5))
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> choosed(n, false);
        int longest = 1;
        for(int i = 0;i < n;++i){
            if(choosed[i]) continue;
            if(nums[i] >= MAX_NUM) continue;
            int square_num = nums[i] * nums[i], length = 1, index;
            while((index = binary_search(i, nums, square_num)) != -1){
                ++length;
                choosed[index] = true;
                if(square_num >= MAX_NUM) break;
                square_num *= square_num;
            }
            longest = max(length, longest);
        }
        if(longest <= 1) return -1;
        return longest;
    }
    int binary_search(int _begin, vector<int> &nums, int target){
        int left = _begin, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
        }
        return -1;
    }
};
