class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        const int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int island_cnt = 0, one_cnt = 0;
        // if it already disconnected, return 0
        for(int i = 0;i < row;++i){
            for(int j = 0;j < col;++j){
                if(grid[i][j] && !visited[i][j]){
                    dfs(grid, i, j, visited);
                    ++island_cnt;
                    if(island_cnt >= 2) return 0;
                }
                if(grid[i][j]) ++one_cnt;
            }
        }
        if(one_cnt <= 2) return one_cnt; //exception: only have 2/1/0 land cell
        for(int i = 0;i < row;++i){
            for(int j = 0;j < col;++j){
                if(grid[i][j] && check(grid, i, j))
                    return 1;
        // if it does not have more than two island && can't only delete one node, the answer is 2
        return 2;
    }
private:
    // check if it can get at least two island with only delete one node
    bool check(vector<vector<int>>& grid, int x, int y){
        const int row = grid.size(), col = grid[0].size();
        int one_cnt = 0;
        if(x >= 1 && grid[x - 1][y]) ++one_cnt;
        if(x + 1 < row && grid[x + 1][y]) ++one_cnt;
        for(int i = y - 1;i <= y + 1;++i){
            if(i >= 0 && i < col && grid[x][i]) ++one_cnt;
        }
        if(one_cnt == 2) return true;
        else if(one_cnt >= 3){
            grid[x][y] = 0;
            int island_cnt = 0;
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for(int i = 0;i < 4;++i){
                int cur_x = x + dir[i].first, cur_y = y + dir[i].second;
                if(cur_x < 0 || cur_x >= row || cur_y < 0 || cur_y >= col) continue;
                if(grid[cur_x][cur_y] && !visited[cur_x][cur_y]){
                    ++island_cnt;
                    if(island_cnt >= 2) return true;
                    dfs(grid, cur_x, cur_y, visited);
                }
            }
            grid[x][y] = 1;
        }
        return false;
    }
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited){
        const int row = grid.size(), col = grid[0].size();
        if(x < 0 || y < 0 || x >= row || y >= col) return;
        if(visited[x][y] || !grid[x][y]) return;
        visited[x][y] = true;
        dfs(grid, x + 1, y, visited);
        dfs(grid, x - 1, y, visited);
        dfs(grid, x, y + 1, visited);
        dfs(grid, x, y - 1, visited);
        return;
    }
};
