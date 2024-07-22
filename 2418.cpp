class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int n = names.size();
        map<int, string> _map;
        for(int i = 0;i < n;++i){
            _map[heights[i]] = names[i];
        }
        vector<string> ans(n);
        int i = 0;
        for(auto it = _map.rbegin();it != _map.rend();++it){
            ans[i++] = it->second;
        }
        return ans;
    }
};
