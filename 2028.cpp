class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int size = rolls.size();
        int sum = 0;
        for(int i = 0;i < size;++i){
            sum += rolls[i];
        }
        int remain_sum = mean * (size + n) - sum;
        if(double(remain_sum) / n > 6) return vector<int>();
        if(remain_sum < n) return vector<int>();
        vector<int> ans(n);
        int index = 0;
        while(remain_sum - 6 > n - index - 1){
            ans[index++] = 6;
            remain_sum -= 6;
        }
        int average = remain_sum / (n - index);
        while(index < n - 1){
            ans[index++] = average;
            remain_sum -= average;
        }
        ans[index] = remain_sum;
        return ans;
    }
};
