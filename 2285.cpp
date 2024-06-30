class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> connect_cnt(n, 0);
        for(auto &road : roads){
            ++connect_cnt[road[0]];
            ++connect_cnt[road[1]];
        }
        sort(connect_cnt.begin(), connect_cnt.end());
        long long ans = 0;
        for(int i = 0;i < n;++i)
            ans += (i + 1) * (long)connect_cnt[i];
        return ans;
    }
};
