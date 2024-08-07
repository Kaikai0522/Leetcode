class Solution {
public:
    string numberToWords(int num) {//transfer bigger and equal than 1000
        if(num == 0) return dic[0]; //except
        string ans = "";
        if(num >= 1000000000){
            ans = ans + dic[num / 1000000000] + " " + dic[1000000000];
            num %= 1000000000;
        }
        if(num >= 1000000){
            if(ans.size()) ans += " ";
            ans = ans + transfer_bigger_than_19(num / 1000000) + " " + dic[1000000];
            num %= 1000000;
        }
        if(num >= 1000){
            if(ans.size()) ans += " ";
            ans = ans + transfer_bigger_than_19(num / 1000) + " " + dic[1000];
            num %= 1000;
        }
        if(ans.size() && num != 0) return ans + " " + transfer_bigger_than_19(num);
        else if(ans.size()) return ans;
        return transfer_bigger_than_19(num);
    }
private:
    inline string transfer_bigger_than_19(int num){
        string tmp = "";
        if(num >= 1000) return "err";
        if(num >= 100){
            tmp = tmp + dic[num / 100] + " " + dic[100];
            num %= 100;
        }
        if(num >= 20){
            if(tmp.size()) tmp += " ";
            tmp = tmp + dic[num / 10 * 10];
            num %= 10;
        }
        if(!num) return tmp;
        if(tmp.size()) return tmp + " " + transfer_bigger_equal_than_0(num);
        return transfer_bigger_equal_than_0(num);
    }
    inline string transfer_bigger_equal_than_0(int num){
        string tmp = "";
        if(num > 19) return "err";
        return dic[num];
    }
    unordered_map<int, string> dic = {
    {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
    {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
    {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},
    {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}
    };
};
