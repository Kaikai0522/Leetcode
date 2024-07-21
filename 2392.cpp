class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int, int> x = _sort(k, rowConditions);
        if(x.size() == 0) return vector<vector<int>>();
        unordered_map<int, int> y = _sort(k, colConditions);
        if(y.size() == 0) return vector<vector<int>>();
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i = 1;i <= k;++i)
            ans[x[i]][y[i]] = i;
        return ans;
    }
private:
    unordered_map<int, int> _sort(int k, vector<vector<int>>& comp){
        const int n = comp.size();
        unordered_map<int, vector<int>> graph;
        vector<int> degree(k + 1, 0);
        graph.reserve(k);
        for(int i = 0;i < n;++i){
            graph[comp[i][0]].push_back(comp[i][1]);
            ++degree[comp[i][1]];
        }
        queue<int> q;
        for(int i = 1;i <= k;++i)
            if(degree[i] == 0)
                q.push(i);
        
        unordered_map<int, int> ans;
        ans.reserve(k);
        int cnt = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            ans[cur] = cnt, ++cnt;
            for(int i = 0;i < graph[cur].size();++i){
                --degree[graph[cur][i]];
                if(degree[graph[cur][i]] == 0)
                    q.push(graph[cur][i]);
            }
        }
        if(ans.size() != k) return {};
        return ans;
    }
};
