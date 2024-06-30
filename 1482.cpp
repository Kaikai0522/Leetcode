class Solution {
private:
    bool check(const int &day, vector<int>& bloomDay,int m, const int &k){
        int cnt = 0, n = bloomDay.size();
        for(int i = 0;i < n;++i){
            if(bloomDay[i] <= day){
                ++cnt;
                if(cnt >= k){
                    cnt = 0;
                    --m;
                    if(!m) return true;
                }
            } 
            else cnt = 0;
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int right = 0, left = INT_MAX, n = bloomDay.size();
        bool flag = false;
        for(int i = 0;i < n;++i){
            right = max(right, bloomDay[i]);
            left = min(left, bloomDay[i]);
        }
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid, bloomDay, m, k)){
                flag = true;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        if(flag) return left;
        return -1;
    }
};
