class Solution {
public:
    string countOfAtoms(string formula) {
        const int n = formula.size();
        stack<map<string, int>> atomic;
        atomic.push(map<string, int>());
        for(int i = 0;i < n;++i){
            if(isupper(formula[i])){
                string tmp{formula[i]};
                while(i + 1 < n && islower(formula[i + 1])){
                    tmp += formula[i + 1];
                    ++i;
                }
                int times = 1, n_index = i + 1;
                while(n_index < n && isdigit(formula[n_index]))
                    ++n_index;
                if(n_index > i + 1)
                    times = stoi(formula.substr(i + 1, n_index - i - 1));
                atomic.top()[tmp] += times;
                i = n_index - 1;
            }
            else if(formula[i] == ')'){
                map<string, int> tmp = atomic.top();
                atomic.pop();
                int times = 1, n_index = i + 1;
                while(n_index < n && isdigit(formula[n_index]))
                    ++n_index;
                if(n_index > i + 1)
                    times = stoi(formula.substr(i + 1, n_index - i - 1));
                for(auto &it : tmp)
                    atomic.top()[it.first] += (it.second * times);
                i = n_index - 1;
            }
            else if(formula[i] == '(')
                atomic.push(map<string, int>());
        }
        string res;
        for(auto &it : atomic.top()){
            res += it.first;
            if(it.second > 1)
                res += to_string(it.second);
        }
        return res;
    }
};
