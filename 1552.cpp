class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1, right = (position.back() - position[0]);
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid, position, m))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
private:
    bool check(const int& m_force, vector<int>& position, int m){
        int n = position.size(), last = position[0];
        --m;
        for(int i = 1;i < n;++i){
            if(position[i] - last >= m_force){
                last = position[i];
                --m;
            }
        }
        if(m <= 0) return true;
        else return false;
    }
};
