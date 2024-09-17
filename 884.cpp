class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream iss1(s1), iss2(s2);
        unordered_map<string, int> hash;
        string word;
        while(iss1 >> word)
            ++hash[word];
        while(iss2 >> word)
            ++hash[word];
        vector<string> ans;
        for(auto &it : hash){
            if(it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};
