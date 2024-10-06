class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1, s2;
        istringstream iss(sentence1);
        string tmp;
        while(iss >> tmp)
            s1.push_back(tmp);
        iss.clear(), iss.str(sentence2);
        while(iss >> tmp)
            s2.push_back(tmp);
        const int s1_size = s1.size(), s2_size = s2.size();
        int prefix_cnt = 0, suffix_cnt = 0;
        for(int i = 0;i < s1_size && i < s2_size && s1[i] == s2[i];++i, ++prefix_cnt);
        for(int i = s1_size - 1, j = s2_size - 1;i >= 0 && j >= 0 && s1[i] == s2[j];--i, --j, ++suffix_cnt);
        if(prefix_cnt + suffix_cnt >= s2_size || prefix_cnt + suffix_cnt >= s1_size)
            return true;
        return false;
    }
};
