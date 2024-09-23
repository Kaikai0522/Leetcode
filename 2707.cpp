class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const int n = s.size();
        vector<int> dp(n, -1);
        unordered_set<string> dic(dictionary.begin(), dictionary.end());
        return solve(dic, dp, 0, s);
    }
    int solve(unordered_set<string> &dic, vector<int> &dp, int index, string &s){
        if(index >= s.size()) return 0;
        if(dp[index] != -1) return dp[index];
        string tmp;
        int extra = INT_MAX;
        for(int i = index;i < s.size();++i){
            tmp += s[i];
            if(dic.find(tmp) != dic.end()){
                extra = min(extra, solve(dic, dp, i + 1, s));
            }
        }
        extra = min(extra, 1 + solve(dic, dp, index + 1, s));
        dp[index] = extra;
        return extra;
    }
};
