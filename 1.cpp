class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<pair<int, int>> sort_nums(n);
        for(int i = 0;i < n;++i){
            sort_nums[i] = {nums[i], i};
        }
        sort(sort_nums.begin(), sort_nums.end());
        for(int i = 0;i < n;++i){
            int index;
            if((index = binary_search(target - sort_nums[i].first, sort_nums, i)) != -1){
                vector<int> ans= {sort_nums[i].second, sort_nums[index].second};
                return ans;
            }
        }
        return vector<int>();
    }
    int binary_search(int target, vector<pair<int, int>> &sort_nums, int ori_i){
        int left = 0, right = sort_nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(sort_nums[mid].first < target){
                left = mid + 1;
            }
            else if(sort_nums[mid].first > target){
                right = mid - 1;
            }
            else{
                if(mid == ori_i){
                    if(mid + 1 < sort_nums.size() && sort_nums[mid + 1].first == target)
                        return mid + 1;
                    else if(mid - 1 >= 0 && sort_nums[mid - 1].first == target)
                        return mid - 1;
                    else break;
                }
                return mid;
            }
        }
        return -1;
    }
};
