class Solution {
public:
    string compressedString(string word) {
        const int n = word.size();
        string res;
        char cur_ch = word[0];
        int cnt = 1;
        for(int i = 1;i < n;++i){
            if(cur_ch != word[i] || cnt >= 9){
                res += to_string(cnt) + cur_ch;
                cur_ch = word[i];
                cnt = 1;
            }
            else ++cnt;
        }
        res += to_string(cnt) + cur_ch;
        return res;
    }
};
