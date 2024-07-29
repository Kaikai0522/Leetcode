class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int n = rating.size();
        int ans = 0;
        for(int i = 1;i < n - 1;++i){
            int left_smaller, right_bigger, left_bigger, right_smaller;
            left_smaller = right_bigger = left_bigger = right_smaller = 0;
            for(int j = 0;j < i;++j){
                if(rating[j] < rating[i]) ++left_smaller;
                else ++left_bigger;
            }
            for(int j = i + 1;j < n;++j){
                if(rating[j] < rating[i]) ++right_smaller;
                else ++right_bigger;
            }
            ans += left_smaller * right_bigger + left_bigger * right_smaller;
        }
        return ans;
    }
};
