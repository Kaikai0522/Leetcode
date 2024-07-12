class Solution {
public:
    int maximumGain(string s, int x, int y) {
        const int n = s.size();
        char first_c, second_c;
        if(x > y)
            first_c = 'a', second_c = 'b';
        else{
            first_c = 'b', second_c = 'a';
            swap(x, y);
        }
        int ans = 0, first_cnt = 0, second_cnt = 0;
        for(int i = 0;i < n;++i){
            if(s[i] == first_c)
                ++first_cnt;
            else if(s[i] == second_c){
                if(first_cnt > 0){
                    ans += x;
                    --first_cnt;
                }
                else
                    ++second_cnt;
            }
            else{
                ans += y * min(first_cnt, second_cnt);
                second_cnt = first_cnt = 0;
            }
        }
        ans += y * min(first_cnt, second_cnt);
        return ans;
    }
};
