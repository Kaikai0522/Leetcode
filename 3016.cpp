class Solution {
public:
    int minimumPushes(string word) {
        const int n = word.size();
        unordered_map<char, int> times;
        times.reserve(26);
        for(int i = 0;i < n;++i){
            times[word[i]]++;
        }
        vector<pair<int, char>> _times;
        for(auto &it : times){
            _times.push_back({it.second, it.first});
        }
        sort(_times.begin(), _times.end());
        int ans = 0, cnt = 8, level = 1;
        for(int i = _times.size() - 1;i >= 0;--i){
            ans += level * _times[i].first;
            --cnt;
            if(!cnt){
                ++level;
                cnt = 8;
            }
        }
        return ans;
    }
};
