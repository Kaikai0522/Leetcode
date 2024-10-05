class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> s1_letters(26, 0), cur_letters(26, 0);
        int left = 0, right = 0;
        while(right < s1.size()){
            ++s1_letters[s1[right] - 'a'];
            ++cur_letters[s2[right] - 'a'];
            ++right;
        }
        if(cur_letters == s1_letters) return true;
        while(right < s2.size()){
            --cur_letters[s2[left] - 'a'];
            ++cur_letters[s2[right] - 'a'];
            if(cur_letters == s1_letters) return true;
            ++left, ++right;
        }
        return false;
    }
};
