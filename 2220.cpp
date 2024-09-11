class Solution {
public:
    int minBitFlips(int start, int goal) {
        int different_bit = start ^ goal, ans = 0;
        while(different_bit > 0){
            if(different_bit & 1)
                ++ans;
            different_bit >>= 1;
        }
        return ans;
    }
};
