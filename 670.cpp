class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        string str_num = to_string(num);
        const int n = str_num.size();
        int cur_max = str_num[n - 1] - '0', target_i = 0;
        for(int i = n - 2;i >= 0;--i){
            if(str_num[i] - '0' < cur_max) target_i = i;
            else cur_max = str_num[i] - '0';
        }
        for(int i = target_i;i < n;++i){
            string tmp = str_num;
            swap(tmp[target_i], tmp[i]);
            ans = max(stoi(tmp), ans);
        }
        return ans;
    }
};
