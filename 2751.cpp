class Solution {
public:
    typedef struct robot{
        int index;
        int health;
        char dir;
    }robot;
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int n = positions.size();
        map<int, robot> robots;
        for(int i = 0;i < n;++i){
            robot tmp;
            tmp.index = i + 1, tmp.health = healths[i], tmp.dir = directions[i];
            robots[positions[i]] = tmp;
        }
        
        vector<pair<int, int>> ans;
        stack<robot> go_R;
        for(auto &r : robots){
            robot& cur_robot = r.second;
            if(go_R.size() > 0 && cur_robot.dir == 'L'){
                // printf("go_R health: %d cur_robot health: %d\n", go_R.top().health, cur_robot.health);
                while(go_R.size() > 0 && cur_robot.health > 0){
                    if(go_R.top().health > cur_robot.health){
                        go_R.top().health--;
                        cur_robot.health = 0;
                    }
                    else if(go_R.top().health < cur_robot.health){
                        go_R.pop();
                        cur_robot.health--;
                    }
                    else{
                        go_R.pop();
                        cur_robot.health = 0;
                    }
                }
                if(go_R.size() == 0 && cur_robot.health > 0){
                    ans.push_back({cur_robot.index, cur_robot.health});
                }
            }
            else if(cur_robot.dir == 'L'){
                ans.push_back({cur_robot.index, cur_robot.health});
            }
            else if(cur_robot.dir == 'R'){
                go_R.push(cur_robot);
            }
        }
        while(go_R.size() > 0){
            robot tmp = go_R.top();go_R.pop();
            ans.push_back({tmp.index, tmp.health});
        }
        sort(ans.begin(), ans.end());
        vector<int> res;
        for(auto &it : ans){
            res.push_back(it.second);
        }
        return res;
    }
};
