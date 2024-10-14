class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        const int n = nums.size();
        priority_queue<int> pq;
        for(int i = 0;i < n;++i)
            pq.push(nums[i]);
        long long score = 0;
        while(k--){
            score += pq.top();
            pq.push(ceil((double)pq.top() / 3));
            pq.pop();
        }
        return score;
    }
};
