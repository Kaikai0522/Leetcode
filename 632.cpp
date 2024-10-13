#define MAX_RANGE (int)1e6
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int n = nums.size();
        vector<int> index(n, 0);
        vector<int> ans = {0, MAX_RANGE};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> windows;
        int max_element = INT_MIN, min_index = 0;
        for(int i = 0;i < n;++i){
            windows.push({nums[i][0], i});
            max_element = max(max_element, nums[i][0]);
        }
        while(true){
            min_index = windows.top().second;
            int min_element = windows.top().first;
            windows.pop();
            if(ans[1] - ans[0] > max_element - min_element)
                ans = {min_element, max_element};
            ++index[min_index];
            if(index[min_index] >= nums[min_index].size()) break;
            windows.push({nums[min_index][index[min_index]], min_index});
            max_element = max(max_element, nums[min_index][index[min_index]]);
        }
        return ans;
    }
};
