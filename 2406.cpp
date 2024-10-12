class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<pair<int, int>> events;
        for(int i = 0;i < n;++i){
            events.push_back({intervals[i][0], 1});
            events.push_back({intervals[i][1], -1});
        }
        sort(events.begin(), events.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        int ans = 0, interval_cnt = 0;
        for(int i = 0;i < 2 * n;++i){
            interval_cnt += events[i].second;
            ans = max(interval_cnt, ans);
        }
        return ans;
    }
};
