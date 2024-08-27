class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // first for the node, second for the probability
        vector<vector<pair<int, double>>> adjlist(n, vector<pair<int, double>>());
        for(int i = 0;i < edges.size();++i){
            adjlist[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjlist[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        // first for the probability, second for the node
        priority_queue<pair<double, int>> pq;
        vector<double> probability(n, 0);
        probability[start_node] = 1;
        pq.push({1, start_node});
        while(!pq.empty()){
            auto [pro, cur] = pq.top();
            pq.pop();
            if(cur == end_node) break;
            if(pro == probability[cur])
                for(int i = 0;i < adjlist[cur].size();++i){
                    double tmp = pro * adjlist[cur][i].second;
                    if(probability[adjlist[cur][i].first] < tmp){
                        probability[adjlist[cur][i].first] = tmp;
                        pq.push({tmp, adjlist[cur][i].first});
                    }
                }
        }
        return probability[end_node];
    }
};
