class Solution {
public:
    long long minEnd(int n, int x) {
        --n;
        vector<bool> push_bit = get_bit(n);
        long long res = x,cur_bit = 1;
        int bits = push_bit.size() - 1;
        while(bits >= 0){
            if((res & cur_bit) == 0){
                if(push_bit[bits])
                    res |= cur_bit;
                --bits;
            }
            cur_bit *= 2;
        }
        return res;
    }
    vector<bool> get_bit(int n){
        if(n == 0) return {};
        vector<bool> res;
        int biggest_bit = pow(2, (int)log2(n));
        while(biggest_bit >= 1){
            res.push_back(n & biggest_bit);
            biggest_bit >>= 1;
        }
        return res;
    }
};
