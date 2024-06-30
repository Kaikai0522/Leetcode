class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        const int n = profits.size();
        for(int i = 0;i < n;++i){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> pq;
        for(int i = 0, j = 0;i < k;++i){
            while(j < n && projects[j].first <= w){
                pq.push(projects[j++].second);
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
