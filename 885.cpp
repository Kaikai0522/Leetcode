class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int step = 1, all_pos = rows * cols, cnt = 1;
        vector<vector<int>> res;
        res.push_back({rStart, cStart});
        while(cnt < all_pos){
            for(int i = 0;i < step;++i){
                ++cStart;
                if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols){
                    res.push_back({rStart, cStart});
                    ++cnt;
                }
            }
            for(int i = 0;i < step;++i){
                ++rStart;
                if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols){
                    res.push_back({rStart, cStart});
                    ++cnt;
                }
            }
            ++step;
            for(int i = 0;i < step;++i){
                --cStart;
                if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols){
                    res.push_back({rStart, cStart});
                    ++cnt;
                }
            }
            for(int i = 0;i < step;++i){
                --rStart;
                if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols){
                    res.push_back({rStart, cStart});
                    ++cnt;
                }
            }
            ++step;
        }
        return res;
    }
};
