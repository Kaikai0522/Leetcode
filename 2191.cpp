class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int n = nums.size();
        vector<pair<int, int>> _nums(n);
        for(int i = 0;i < n;++i)
            _nums[i] = {transfer(mapping, nums[i]), nums[i]};
        stable_sort(_nums.begin(), _nums.end(), compare);
        for(int i = 0;i < n;++i)
            nums[i] = _nums[i].second;
        return nums;
    }
private:
    static bool compare(const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
    }
    int transfer(vector<int>& mapping, int target){
        int ans = 0, i = 0;
        do{
            int tmp = target % 10;
            ans += mapping[tmp] * pow(10, i);
            target /= 10;
            ++i;
        } while(target > 0);
        return ans;
    }
};
