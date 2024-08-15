class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        const int n = bills.size();
        vector<int> change(2, 0);
        for(int i = 0;i < n;++i){
            if(bills[i] == 5) ++change[0];
            else if(bills[i] == 10){
                if(change[0] <= 0) return false;
                --change[0];
                ++change[1];
            }
            else{
                if((change[0] <= 0 || change[1] <= 0) && change[0] < 3) return false;
                else if(change[0] > 0 && change[1] > 0){
                    --change[0];
                    --change[1];
                }
                else
                    change[0] -= 3;
            }
        }
        return true;
    }
};
