class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream iss(sentence);
        vector<string> sentences;
        string input;
        while(iss >> input)
            sentences.push_back(input);
        const int n = sentences.size();
        char ch = sentences[0].back();
        for(int i = 1;i < n;++i){
            if(ch != sentences[i][0]) return false;
            ch = sentences[i].back();
        }
        if(ch != sentences[0][0]) return false;
        return true;
    }
};
