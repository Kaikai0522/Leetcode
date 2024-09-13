class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int n = arr.size();
        vector<int> prefix(n), ans(queries.size());
        prefix[0] = arr[0];
        for(int i = 1;i < n;++i){
            prefix[i] = prefix[i - 1] ^ arr[i];
        }
        for(int i = 0;i < queries.size();++i){
            if(queries[i][0] >= 1)
                ans[i] = prefix[queries[i][0] - 1] ^ prefix[queries[i][1]];
            else
                ans[i] = prefix[queries[i][1]];
        }
        return ans;
    }
};
