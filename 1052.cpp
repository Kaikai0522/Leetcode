class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        const int n = customers.size();
        int ans = 0, max_unsatisfied = 0;
        for(int i = 0;i < minutes;++i){
            if(!grumpy[i])
                ans += customers[i];
            else
                max_unsatisfied += customers[i];
        }
        int left = 0, tmp = max_unsatisfied;
        for(int i = minutes;i < n;++i, ++left){
            if(!grumpy[i])
                ans += customers[i];
            else
                tmp += customers[i];
            if(grumpy[left])
                tmp -= customers[left];
            max_unsatisfied = max(max_unsatisfied, tmp);
        }
        return ans + max_unsatisfied;
    }
};
