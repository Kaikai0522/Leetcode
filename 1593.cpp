class Solution {
public:
    int maxUniqueSplit(string s) {
        const int n = s.size();
        unordered_set<string> str_set;
        int ans = 0;
        backtracking(s, ans, str_set, 0);
        return ans;
    }
    void backtracking(string &s, int &ans, unordered_set<string> &str_set, int index){
        if(index >= s.size()){
            ans = max(ans, (int)str_set.size());
            return;
        }
        string tmp;
        for(int i = index;i < s.size();++i){
            tmp += s[i];
            if(str_set.find(tmp) == str_set.end()){
                str_set.insert(tmp);
                backtracking(s, ans, str_set, i + 1);
                str_set.erase(tmp);
            }
        }
        return;
    }
};
