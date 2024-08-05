class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        const int n = arr.size();
        unordered_map<string, int> appeared;
        for(int i = 0;i < n;++i)
            ++appeared[arr[i]];

        int ans_i = 0, i = 0, j = 0;
        for(;i < n && j < k;++i){
            if(appeared[arr[i]] == 1){
                ++j;
                ans_i = i;
            }
        }
        if(i == n && j < k) return "";
        return arr[ans_i];
    }
};
