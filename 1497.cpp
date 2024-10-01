class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        const int n = arr.size();
        vector<int> remainder(k, 0);
        for(int i = 0;i < n;++i){
            if(arr[i] < 0) {
                arr[i] = -arr[i];
                ++remainder[(k - arr[i] % k) % k];
            }
            else
                ++remainder[arr[i] % k];
        }
        int left = 1, right = k - 1;
        for(;left < right;++left, --right){
            if(remainder[left] != remainder[right]) 
                return false;
        }
        if(left == right && remainder[left] & 1) return false;
        return true;
    }
};
