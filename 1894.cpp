class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        const int n = chalk.size();
        long sum = 0;
        for(int i = 0;i < n;++i){
            sum += chalk[i];
        }
        k %= sum;
        int ans = 0;
        while(k - chalk[ans] >= 0){
            k -= chalk[ans];
            ++ans;
        }
        return ans;
    }
};
