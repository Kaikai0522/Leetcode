class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_multiset _target(target.begin(), target.end()), _arr(arr.begin(), arr.end());
        return _target == _arr;
    }
};
