class Solution {
public:
    char findKthBit(int n, int k) {
        return '0' + findK(k);
    }
    bool findK(int k){
        if(k == 1) return 0;
        else if((k & (k - 1)) == 0) return 1; // 判斷是不是二的指數次
        return !findK(pow(2, (int)ceil(log2(k + 1))) - k);
    }
};
