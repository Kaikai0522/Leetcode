class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_nums = {1};
        vector<queue<long>> lists(3, queue<long>());
        lists[0].push(2), lists[1].push(3), lists[2].push(5);
        unordered_set<long> added;
        added.reserve(1690);
        while(ugly_nums.size() < n){
            int smallest_i = 0;
            long smallest = lists[0].front();
            if(lists[1].front() < smallest){
                smallest_i = 1;
                smallest = lists[1].front();
            }
            if(lists[2].front() < smallest){
                smallest_i = 2;
                smallest = lists[2].front();
            }
            lists[smallest_i].pop();
            ugly_nums.push_back(smallest);
            if(added.find(smallest * 2) == added.end()){
                added.insert(smallest * 2);
                lists[0].push(smallest * 2);
            }
            if(added.find(smallest * 3) == added.end()){
                added.insert(smallest * 3);
                lists[1].push(smallest * 3);
            }
            if(added.find(smallest * 5) == added.end()){
                added.insert(smallest * 5);
                lists[2].push(smallest * 5);
            }
        }
        return ugly_nums[n - 1];
    }
};
