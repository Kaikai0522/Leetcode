class Solution {
public:
    int minSwaps(string s) {
        const int n = s.size();
        int left = 0, right = n - 1;
        int open_b = 0, close_b = 0, ans = 0;
        while(right >= 0 && s[right] != '[') --right;
        while(left < right){
            if(s[left] == '[') ++open_b;
            else {
                ++close_b;
                if(close_b > open_b){
                    swap(s[left], s[right]);
                    --close_b, ++open_b;
                    ++ans;
                    while(right >= 0 && s[right] != '[') --right;
                }
            }
            ++left;
        }
        return ans;
    }
};
