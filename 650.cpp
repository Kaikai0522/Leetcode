class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        int ans = 0;
        for(int i = 2;i * i<= n; ++i){
            if(n % i == 0){
                ans += i;
                n /= i;
                --i;
            }
        }
        ans += n;
        return ans;
    }
};
