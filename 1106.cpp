class Solution {
public:
    bool parseBoolExpr(string expression) {
        const int n = expression.size();
        stack<char> op;
        for(int i = n - 1;i >= 0;--i){
            if(expression[i] == ',') continue;
            if(expression[i] != '('){
                op.push(expression[i]);
            }
            else{
                char cur_op = expression[i - 1];
                bool state = op.top() == 't'? true : false;
                op.pop();
                if(cur_op == '&'){
                    while(op.top() != ')'){
                        state &= (op.top()) == 't'? true : false;
                        op.pop();
                    }
                    op.pop(); //pop ')'
                }
                else if(cur_op == '|'){
                    while(op.top() != ')'){
                        state |= (op.top()) == 't'? true : false;
                        op.pop();
                    }
                    op.pop(); //pop ')'
                }
                else if(cur_op == '!'){
                    state = !state;
                    op.pop(); //pop ')'
                }
                op.push(state == true?'t' : 'f');
                --i;
            }
        }
        return op.top() == 't'? true : false;
    }
};
