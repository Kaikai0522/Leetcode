class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        const int n = customers.size();
        long cur_time = customers[0][0], total_wait = 0;
        for(int i = 0;i < n;++i){
            if(cur_time < customers[i][0])
                cur_time = customers[i][0];
            cur_time += customers[i][1];
            total_wait += (cur_time - customers[i][0]);
        }
        return (double)total_wait / n;
    }
};
