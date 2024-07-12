class Solution {
public:
    int maximumGain(string s, int x, int y) {
        const int n = s.size();
        char first_c = 'a', second_c = 'b';
        if(y > x){
            swap(first_c, second_c);
            swap(x, y);
        }
        int ans = 0;
        for(int i = 0;i < n - 1;++i){
            if(s[i] == first_c && s[i + 1] == second_c){
                ans += x;
                s.erase(i, 2);
                i = max(-1, i - 2);
            }
        }
        for(int i = 0;i < n - 1;++i){
            if(s[i] == second_c && s[i + 1] == first_c){
                ans += y;
                s.erase(i, 2);
                i = max(-1, i - 2);
            }
        }
        cout << s;
        return ans;
    }
};
