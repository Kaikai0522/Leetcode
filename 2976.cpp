#define INF INT_MAX / 2 - 2
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int n = source.size(), m = original.size();
        vector<vector<int>> dist(26, vector<int>(26, INF));
        for(int i = 0;i < 26;++i)
            dist[i][i] = 0;
        for(int i = 0;i < m;++i)
            dist[original[i] - 'a'][changed[i] - 'a'] = min((int)cost[i], dist[original[i] - 'a'][changed[i] - 'a']);

        for(int k = 0;k < 26;++k)
            for(int i = 0;i < 26;++i)
                for(int j = 0;j < 26;++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    
        long long ans = 0;
        for(int i = 0;i < n;++i){
            if(dist[source[i] - 'a'][target[i] - 'a'] == INF) return -1;
            ans += dist[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};
