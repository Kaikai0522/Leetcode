class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty_bottles = numBottles, ans = numBottles;
        while(empty_bottles >= numExchange){
            int tmp = empty_bottles / numExchange;
            ans += tmp;
            empty_bottles = empty_bottles % numExchange + tmp;
        }
        return ans;
    }
};
