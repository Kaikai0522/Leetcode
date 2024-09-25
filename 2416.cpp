class Trie{
public:
    class TrieNode{
    public:
        TrieNode(){
            for(int i = 0;i < 26;i++)
                children[i]=nullptr;
            cnt = 0;
        }
        int cnt;
        TrieNode* children[26];
    };
    Trie(){
        root = new TrieNode();
    }
    void insert(string &str){
        const int n = str.size();
        TrieNode *node = root;
        for(char &ch : str){
            int index = ch - 'a';
            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }
            node->children[index]->cnt++;
            node = node->children[index];
        }
        return;
    }
    int search(const string &str){
        const int n = str.size();
        TrieNode *node = root;
        int cnt = 0;
        for(int i = 0;i < n;++i){
            node = node->children[str[i] - 'a'];
            cnt += node->cnt;
        }
        return cnt;
    }
    TrieNode *root;
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        const int n = words.size();
        Trie tree;
        for(int i = 0;i < n;++i){
            tree.insert(words[i]);
        }
        vector<int> ans(n, 0);
        for(int i = 0;i < n;++i){
            ans[i] = tree.search(words[i]);
        }
        return ans;
    }
};
