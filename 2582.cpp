class Solution {
public:
    int passThePillow(int n, int time) {
        int move = 1, ans = 1;
        while(time--){
            ans += move; 
            if(ans == n) move = -1;
            else if(ans == 1) move = 1;
        }
        return ans;
    }
};
