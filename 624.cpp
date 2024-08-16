class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        const int n = arrays.size();
        int biggest1 = INT_MIN, biggest2 = INT_MIN, smallest1 = INT_MAX, smallest2 = INT_MAX, biggest_i, smallest_i;
        for(int i = 0;i < n;++i){
            if(arrays[i].back() > biggest1) {
                biggest2 = biggest1;
                biggest1 = arrays[i].back();
                biggest_i = i;
            }
            else if(arrays[i].back() > biggest2) biggest2 = arrays[i].back();
            if(arrays[i][0] < smallest1) {
                smallest2 = smallest1;
                smallest1 = arrays[i][0];
                smallest_i = i;
            }
            else if(arrays[i][0] < smallest2) smallest2 = arrays[i][0];
        }
        if(biggest_i == smallest_i){
            if(biggest1 - biggest2 > smallest2 - smallest1)
               return biggest1 - smallest2;
            else
                return biggest2 - smallest1;
        }
        return biggest1 - smallest1;
    }
};
