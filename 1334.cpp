class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> res(n);
        vector<vector<pair<int, int>>> adjlist(n, vector<pair<int, int>>());
        for(int i = 0;i < edges.size();++i){
            adjlist[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjlist[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int min_city = INT_MAX, ans = -1;
        for(int i = 0;i < n;++i){
            int tmp = dijkstra(n, adjlist, i, distanceThreshold);
            if(min_city >= tmp){
                min_city = tmp;
                ans = i;
            }
        }
        return ans;
    }
private:
    int dijkstra(int n, vector<vector<pair<int, int>>> &adjlist, int start, int &distanceThreshold){
        vector<int> dist(n, INT_MAX - 100000);
        vector<bool> visit(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        dist[start] = 0;
        while(!pq.empty()){
            int vertex = pq.top().second;
            pq.pop();
            if(visit[vertex]) continue;
            visit[vertex] = true;
            for(int i = 0;i < adjlist[vertex].size();++i){
                int v = adjlist[vertex][i].first, w = adjlist[vertex][i].second;
                if(!visit[v] && dist[vertex] + w < dist[v] && dist[vertex] + w <= distanceThreshold){
                    dist[v] = dist[vertex] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int res = 0;
        for(int i = 0;i < n;++i)
            if(dist[i] <= distanceThreshold && i != start)
                ++res;
        
        return res;
    }
};
