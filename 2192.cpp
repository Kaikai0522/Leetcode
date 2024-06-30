class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<bool> edge_cnt(n, false);
        vector<vector<int>> adjlist(n, vector<int>());
        for(auto &edge : edges){
            adjlist[edge[1]].push_back(edge[0]);
            edge_cnt[edge[0]] = true;
        }
        vector<set<int>> ans(n, set<int>());
        vector<bool> searched(n, false);
        for(int i = 0;i < n;++i)
            if(!edge_cnt[i])
                search(i, adjlist, searched, ans);
        
        return convert_result(ans);
    }
private:
    set<int> search(int cur_node, vector<vector<int>> &adjlist, vector<bool> &searched, vector<set<int>> &ans){
        if(searched[cur_node]) return ans[cur_node];
        for(int& connected : adjlist[cur_node]){
            set<int> res = search(connected, adjlist, searched, ans);
            ans[cur_node].insert(res.begin(), res.end());
            ans[cur_node].insert(connected);
            searched[connected] = true;
        }
        return ans[cur_node];
    }
    vector<vector<int>> convert_result(vector<set<int>> &input){
        vector<vector<int>> output;
        output.reserve(input.size());
        for(set<int> &it : input){
            output.emplace_back(vector<int>(it.begin(), it.end()));
        }
        return output;
    }
};
