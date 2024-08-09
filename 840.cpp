class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int row = grid.size(), col = grid[0].size();
        int ans = 0;
        for(int i = 0;i <= row - 3;++i)
            for(int j = 0;j <= col - 3;++j)
                ans += check(grid, i, j);
        
        return ans;
    }
private:
    bool check(vector<vector<int>>& grid, int x, int y){
        const int row = grid.size(), col = grid[0].size();
        int total = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
        if(total != grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2] ||
           total != grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2] ||
           total != grid[x][y] + grid[x + 1][y] + grid[x + 2][y] ||
           total != grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 2][y + 1] ||
           total != grid[x][y + 2] + grid[x + 1][y + 2] + grid[x + 2][y + 2] ||
           total != grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] ||
           total != grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2])
           return false;
        vector<bool> occur(9, false);
        for(int i = x;i < x + 3;++i){
            for(int j = y;j < y + 3;++j){
                if(grid[i][j] < 1 || grid[i][j] > 9 || occur[grid[i][j] - 1]) return false;
                occur[grid[i][j] - 1] = true;
            }
        }
        return true;
    }
};
