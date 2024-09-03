class Solution {
public:
    int getLucky(string s, int k) {
        string transfer_str;
        for(auto &c : s)
            transfer_str += to_string(c - 'a' + 1);
        while(k--){
            int tmp = 0;
            for(auto &c : transfer_str)
                tmp += c - '0';
            transfer_str = to_string(tmp);
        }
        return stoi(transfer_str);
    }
};
