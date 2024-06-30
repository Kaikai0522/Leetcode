class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        const int n = nums.size();
        queue<bool> history;
        bool convert_bit = !nums[0];
        int ans = convert_bit;
        history.push(convert_bit);
        for(int i = 1;i < n;++i){
            if(i >= k){
                convert_bit ^= history.front();
                history.pop();
            }
            bool cur_bit = nums[i] ^ convert_bit;
            if(cur_bit)
                history.push(false);
            else{
                if(i + k >= n + 1) return -1;
                convert_bit ^= 1;
                history.push(true);
                ++ans;
            }
        }
        return ans;
    }
};
