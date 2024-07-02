class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i1 = 0, i2 = 0;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]){
                ans.push_back(nums1[i1]);
                ++i1, ++i2;
            }
            else if(nums1[i1] < nums2[i2])
                ++i1;
            else
                ++i2;
        }
        return ans;
    }
};
