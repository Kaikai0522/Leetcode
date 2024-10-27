class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        for(int i = 0;i < matrix.size();++i){
            for(int j = 0;j < matrix[0].size();++j){
                ans += count_current_squares(matrix, i, j);
            }
        }
        return ans;
    }
    int count_current_squares(vector<vector<int>>& matrix, int x, int y){
        if(matrix[x][y] == 0) return 0;
        int cnt = 1, step = 2;
        while(x + step - 1 < matrix.size() && y + step - 1 < matrix[0].size()){
            int topright_y = y + step - 1, topright_x = x, 
                bottomleft_x = x + step - 1, bottomleft_y = y;
            for(int i = 0;i < step;++i, ++topright_x){
                if(matrix[topright_x][topright_y] == 0) 
                    return cnt;
            }
            for(int i = 0;i < step;++i, ++bottomleft_y){
                if(matrix[bottomleft_x][bottomleft_y] == 0)
                    return cnt;
            }
            ++step, ++cnt;
        }
        return cnt;
    }
};
