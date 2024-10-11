class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        const int n = times.size();
        priority_queue<int, vector<int>, greater<int>> unoccupied;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leave_time;
        int target = times[targetFriend][0];
        sort(times.begin(), times.end());
        for(int i = 0;i < n;++i){
            unoccupied.push(i);
            while(!leave_time.empty() && leave_time.top().first <= times[i][0]){
                unoccupied.push(leave_time.top().second);
                leave_time.pop();
            }
            if(times[i][0] == target) return unoccupied.top();
            leave_time.push({times[i][1], unoccupied.top()});
            unoccupied.pop();
        }
        return -1;
    }
};
