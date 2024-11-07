class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        const int n = candidates.size();
        vector<int> bit_cnt(25, 0);
        for(int i = 0;i < n;++i){
            for(int j = 0;candidates[i] > 0;++j){
                if(candidates[i] & 1){
                    bit_cnt[j]++;
                }
                candidates[i] >>= 1;
            }
        }
        return *max_element(bit_cnt.begin(), bit_cnt.end());
    }
};
