class Solution {
public:
    int findComplement(int num) {
        long two_pow = 1;
        for(int i = 0;two_pow < num;++i){
            two_pow *= 2;
        }
        if(two_pow == num) return num - 1;
        return two_pow - num - 1;
    }
};
