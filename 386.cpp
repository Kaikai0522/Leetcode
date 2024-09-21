class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int cur_num = 1;
        for(int i = 0;i < n;++i){
            ans[i] = cur_num;
            if(cur_num * 10 <= n){
                cur_num *= 10;
            }
            else{
                while(cur_num % 10 == 9 || cur_num >= n){
                    cur_num /= 10;
                }
                cur_num += 1;
            }
        }
        return ans;
    }
};
