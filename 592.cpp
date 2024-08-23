class Solution {
public:
    string fractionAddition(string expression) {
        const int n = expression.size();
        string tmp(1, expression[0]);
        int index = 1;
        for(;index < n;++index){
            if(expression[index] == '+' || expression[index] == '-') break;
            tmp += expression[index];
        }
        Fraction res(tmp);
        tmp = "";
        while(index < n){
            char op = expression[index++];
            tmp += expression[index++];
            while(index < n && expression[index] != '+' && expression[index] != '-'){
                tmp += expression[index];
                ++index;
            }
            if(op == '+'){
                res = res + Fraction(tmp);
            }
            else{
                res = res - Fraction(tmp);
            }
            tmp = "";
        }
        return res.toString();
    }
private:
    class Fraction{
    public:
        Fraction(){}
        Fraction(string str){
            int index = 0;
            if(str[0] == '-') {
                sign = 1;
                ++index;
            }
            else sign = 0;
            int tmp = index;
            while(str[tmp] != '/') ++tmp;
            numerator = stoi(str.substr(index, tmp - index));
            denominator = stoi(str.substr(tmp + 1));
        }
        string toString(){
            string res;
            if(sign) res += "-";
            res += to_string(numerator);
            res += "/";
            res += to_string(denominator);
            return res;
        }
        Fraction operator-(const Fraction &frac){
            int frac_numerator = frac.numerator;
            if(this->denominator != frac.denominator){
                frac_numerator *= this->denominator;
                this->denominator *= frac.denominator;
                this->numerator *= frac.denominator;
            }
            Fraction tmp;
            tmp.denominator = this->denominator;
            if(this->sign ^ frac.sign){
                tmp.sign = this->sign;
                tmp.numerator = this->numerator + frac_numerator;
                simplify_fractions(tmp);
            }
            else{
                tmp.sign = 0;
                if(this->sign == 0 && this->numerator < frac_numerator){
                    tmp.sign = 1;
                }
                else if(this->sign == 1 && this->numerator > frac_numerator){
                    tmp.sign = 1;
                }
                if(this->numerator < frac_numerator) swap(this->numerator, frac_numerator);
                tmp.numerator = this->numerator - frac_numerator;
                simplify_fractions(tmp);
            }
            return tmp;
        }
        Fraction operator+(const Fraction &frac){
            int frac_numerator = frac.numerator;
            if(this->denominator != frac.denominator){
                frac_numerator *= this->denominator;
                this->denominator *= frac.denominator;
                this->numerator *= frac.denominator;
            }
            Fraction tmp;
            tmp.denominator = this->denominator;
            if(this->sign ^ frac.sign){
                tmp.sign = 0;
                if(this->numerator < frac_numerator){
                    swap(this->numerator, frac_numerator);
                    if(frac.sign == 1) tmp.sign = 1;
                }
                else if(this->sign == 1) tmp.sign = 1;
                tmp.numerator = this->numerator - frac_numerator;
            }
            else{
                tmp.sign = this->sign;
                tmp.numerator = this->numerator + frac_numerator;
            }
            simplify_fractions(tmp);
            return tmp;
        }
        void simplify_fractions(Fraction &tmp){
            if(tmp.numerator == 0) {
                tmp = Fraction("0/1");
                return;
            }
            int _min = min(tmp.numerator, tmp.denominator);
            for(int i = 2;i * i<= _min;++i){
                if(tmp.numerator % i == 0 && tmp.denominator % i == 0){
                    tmp.numerator /= i;
                    tmp.denominator /= i;
                    _min = min(tmp.numerator, tmp.denominator);
                    --i;
                }
            }
            if(tmp.numerator % _min == 0 && tmp.denominator % _min == 0){
                tmp.numerator /= _min;
                tmp.denominator /= _min;
            }
            return;
        }
        int numerator;
        int denominator;
        bool sign;
    };
};
