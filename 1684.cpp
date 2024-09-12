class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowed_set(allowed.begin(), allowed.end());
        int ans = 0;
        for(auto &word : words){
            bool allow = true;
            for(auto &c : word){
                if(allowed_set.find(c) == allowed_set.end()){
                    allow = false;
                    break;
                }
            }
            if(allow) ++ans;
        }
        return ans;
    }
};
