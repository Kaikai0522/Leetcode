class Solution {
public:
    int minAddToMakeValid(string s) {
        const int n = s.size();
        int open_cnt = 0, close_cnt = 0, ans = 0;
        for(int i = 0;i < n;++i){
            if(s[i] == '('){
                ++open_cnt;
            }
            else{
                ++close_cnt;
                while(open_cnt > 0 && close_cnt > 0){
                    --open_cnt, --close_cnt;
                }
                ans += close_cnt;
                close_cnt = 0;
            }
        }
        return open_cnt + ans;
    }
};
