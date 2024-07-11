class Solution {
public:
    string reverseParentheses(string s) {
        const int n = s.size();
        vector<int> wormholes(n);
        stack<int> brackets;
        for(int i = 0;i < n;++i){
            if(s[i] == '(')
                brackets.push(i);
            else if(s[i] == ')'){
                int tmp = brackets.top();
                brackets.pop();
                wormholes[i] = tmp;
                wormholes[tmp] = i;
            }
        }
        string ans;
        for(int i = 0, dir = 1;i < n;i += dir){
            if(s[i] == '(' || s[i] == ')'){
                dir = -dir;
                i = wormholes[i];
            }
            else ans += s[i];
        }
        return ans;
    }
};
