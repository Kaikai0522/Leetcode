class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int n = nums.size();
        if(n <= 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<int> left ={nums[1]-nums[0], nums[2]-nums[1], nums[3]-nums[2]},
          right ={nums[n-1]-nums[n-2], nums[n-2]-nums[n-3], nums[n-3]-nums[n-4]};
        for(int i = 0;i < 4;++i){
            int temp=0;
            for(int j = 0;j<i;++j)
                temp+=left[j];
            for(int j=0;j<3-i;++j)
                temp+=right[j];
            ans = max(ans, temp);
        }
        return nums.back()-nums[0]-ans;
    }
};
