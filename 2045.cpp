class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjlist(n + 1, vector<int>());
        for(int i = 0;i < edges.size();++i){
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        // node previous_node(do not go back)
        queue<pair<int, int>> q;
        vector<int> visited(n + 1, 0);
        int cur_time = 0;
        bool reach = false;
        q.push({1, 1});
        while(!q.empty()){
            // if it's red
            if((cur_time / change) & 1) {
                cur_time += (change - (cur_time % change));
                continue;
            }
            int _size = q.size();
            // not to push same node into queue at the same time
            vector<bool> in_queue(n + 1, false);
            while(_size--){
                int cur = q.front().first, prev = q.front().second;
                q.pop();
                // a node can be visited up to twice
                if(visited[cur] >= 2) continue;
                ++visited[cur];
                for(int i = 0;i < adjlist[cur].size();++i){
                    if(in_queue[adjlist[cur][i]]) continue;
                    // no to go back || when cur is n, it need to go back || when previous node is n and adjlist[cur][i] is n, it need to go back
                    if(adjlist[cur][i] != prev || cur == n || (prev == n && adjlist[cur][i] == n)){
                        if(adjlist[cur][i] == n){
                            // second time visit n
                            if(reach) return cur_time + time;
                            // first time visit n
                            else reach = true;
                        }
                        in_queue[adjlist[cur][i]] = true;
                        q.push({adjlist[cur][i], cur});
                    }
                }
            }
            cur_time += time;
        }
        return -1;
    }
};
