class Solution {
public:
    int findTheLongestSubstring(string s) {
        const int n = s.size();
        int bitmask = 0;
        unordered_map<int, int> appeared; //bitmask(key) for index(value)
        appeared.reserve(n + 1);
        appeared[0] = 0;
        int ans = 0;
        for(int i = 1;i <= n;++i){
            if(s[i - 1] == 'a') bitmask ^= 1;
            else if(s[i - 1] == 'e') bitmask ^= 2;
            else if(s[i - 1] == 'i') bitmask ^= 4;
            else if(s[i - 1] == 'o') bitmask ^= 8;
            else if(s[i - 1] == 'u') bitmask ^= 16;
            if(appeared.find(bitmask) != appeared.end())
                ans = max(ans, i - appeared[bitmask]);
            else
                appeared[bitmask] = i;
        }
        return ans;
    }
};
