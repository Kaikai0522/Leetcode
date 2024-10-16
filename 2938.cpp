class Solution {
public:
    long long minimumSteps(string s) {
        const int n = s.size();
        int right_zero = n - 1, index = n - 1;
        long long ans = 0;
        while(index >= 0){
            if(s[index] == '1'){
                ans += right_zero - index;
                --right_zero;
            }
            --index;
        }
        return ans;
    }
};
