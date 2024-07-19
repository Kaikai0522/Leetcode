class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> ans, col_max(n, INT_MIN), row_min;
        for(int i = 0;i < m;++i){
            int min_num = INT_MAX;
            for(int j = 0;j < n;++j){
                min_num = min(min_num, matrix[i][j]);
                col_max[j] = max(col_max[j], matrix[i][j]);
            }
            row_min.push_back(min_num);
        }
        return intersection(col_max, row_min);
    }
private:
    vector<int> intersection(vector<int> &a, vector<int> &b){
        vector<int> res;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
        return res;
    }
};
