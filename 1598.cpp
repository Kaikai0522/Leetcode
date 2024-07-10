class Solution {
public:
    int minOperations(vector<string>& logs) {
        const int n = logs.size();
        int ans = 0;
        for(int i = 0;i < n;++i){
            if(logs[i][0] != '.')
                ++ans;
            else if(logs[i][0] == '.' && logs[i][1] == '.')
                if(ans > 0) --ans;
        }
        return ans;
    }
};
