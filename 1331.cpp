class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        const int n = arr.size();
        vector<int> sort_rank(arr.begin(), arr.end());
        sort(sort_rank.begin(), sort_rank.end());
        unordered_map<int, int> ranking;
        for(int i = 0;i < n;++i){
            ranking[sort_rank[i]] = ranking.size() + 1;
            while(i + 1 < n && sort_rank[i] == sort_rank[i + 1]) ++i;
        }
        for(int i = 0;i < n;++i)
            arr[i] = ranking[arr[i]];
        return arr;
    }
};
