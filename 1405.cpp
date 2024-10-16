class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> max_occur;
        if(a > 0) max_occur.push({a, 'a'});
        if(b > 0) max_occur.push({b, 'b'});
        if(c > 0) max_occur.push({c, 'c'});
        string ans = "";
        while(ans.size() == 0 || !max_occur.empty() && (ans.size() > 0 && ans.back() != max_occur.top().second)){
            auto [max_cnt, ch] = max_occur.top();
            max_occur.pop();
            string push_str = (max_cnt >= 2)? string(1, ch) + ch : string(1, ch);
            ans += push_str;
            max_cnt -= push_str.size();
            if(max_occur.top().first > 0 && max_occur.top().first <= max_cnt){
                auto [tmp_cnt, tmp_ch] = max_occur.top();
                max_occur.pop();
                ans += tmp_ch;
                if(tmp_cnt - 1 > 0) max_occur.push({tmp_cnt - 1, tmp_ch});
            }
            if(max_cnt > 0) max_occur.push({max_cnt, ch});
        }
        return ans;
    }
};
