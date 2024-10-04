class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        const int n = skill.size();
        long long sum = 0;
        vector<int> skill_hash(1001, 0);
        for(int i = 0;i < n;++i){
            sum += skill[i];
            ++skill_hash[skill[i]];
        }
        int teams_number = n / 2, target = sum / teams_number;
        long long ans = 0;
        if(sum % teams_number != 0) {return -1;}
        for(int i = 0;i < n;++i){
            if(skill_hash[skill[i]] == 0) continue;
            --skill_hash[skill[i]];
            if(skill[i] >= target || skill_hash[target - skill[i]] == 0)
                return -1;
            --skill_hash[target - skill[i]];
            ans += (skill[i] * (target - skill[i]));
        }
        return ans;
    }
};
