enum DIR{north = 0, east, south, west};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, hash_pair> obstacles_set;
        for(int i = 0;i < obstacles.size();++i){
            obstacles_set.insert({obstacles[i][0], obstacles[i][1]});
        }
        int x = 0, y = 0, ans = 0;
        DIR direction = north;
        for(int i = 0;i < commands.size();++i){
            if(commands[i] == -1) direction = DIR((direction + 1) % 4);
            else if(commands[i] == -2) direction = DIR((direction + 3) % 4);
            else{
                int x_move = 0, y_move = 0;
                if(direction == north) y_move = 1;
                else if(direction == east) x_move = 1;
                else if(direction == south) y_move = -1;
                else if(direction == west) x_move = -1;
                while(commands[i]--){
                    x += x_move;
                    y += y_move;
                    if(obstacles_set.find({x, y}) != obstacles_set.end()){
                        x -= x_move;
                        y -= y_move;
                        break;
                    }
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
private:
    struct hash_pair {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
};
