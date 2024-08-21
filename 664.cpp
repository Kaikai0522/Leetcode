class Solution {
public:
    int strangePrinter(string s) {
        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for(int i = n - 2;i >= 0;--i){
            for(int j = i + 1;j < n;++j){
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j];
                else{
                    int _min = INT_MAX;
                    for(int i1 = i, j1 = i, i2 = i + 1, j2 = j;j1 < j;++j1, ++i2)
                        _min = min(dp[i1][j1] + dp[i2][j2], _min);
                    dp[i][j] = _min;
                }
            }
        }
        return dp[0][n - 1];
    }
};
