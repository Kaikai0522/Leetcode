class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0, j = 0;i < m && j < n;i += (rowSum[i] == 0), j += (colSum[j] == 0)){
            int _min = min(rowSum[i], colSum[j]);
            ans[i][j] = _min;
            rowSum[i] -= _min;
            colSum[j] -= _min;
        }
        return ans;
    }
};
