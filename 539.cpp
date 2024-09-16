class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        const int n = timePoints.size();
        vector<int> time(n);
        for(int i = 0;i < n;++i)
            time[i] = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2));
        sort(time.begin(), time.end());
        int ans = time[0] + 1440 - time.back();
        for(int i = 0;i < n - 1;++i)
            ans = min(ans, time[i + 1] - time[i]);
        return ans;
    }
};
