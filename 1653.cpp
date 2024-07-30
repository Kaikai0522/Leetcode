class Solution {
public:
    int minimumDeletions(string s) {
        const int n = s.size();
        int ans, a_cnt = 0, b_cnt = 0;
        vector<int> front_b(n, 0), back_a(n, 0);
        for(int i = 0, j = n - 1;i < n;++i, --j){
            if(s[i] == 'b') ++b_cnt;
            front_b[i] = b_cnt;
            if(s[j] == 'a') ++a_cnt;
            back_a[j] = a_cnt;
        }
        ans = min(a_cnt, b_cnt);
        for(int i = 0;i < n - 1;++i)
            ans = min(front_b[i] + back_a[i + 1], ans);
        return ans;
    }
};
