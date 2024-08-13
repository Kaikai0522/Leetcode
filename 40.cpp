class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> component;
        vector<vector<int>> ans;
        find_combination(0, component, candidates, ans, target);
        return ans;
    }
private:
    void find_combination(int index, vector<int> &component, vector<int>& candidates, vector<vector<int>> &ans, int &target){
        if(target < 0) return;
        else if(target == 0) {
            ans.push_back(component);
            return;
        }
        if(index >= candidates.size()) return;
        component.push_back(candidates[index]);
        target -= candidates[index];
        find_combination(index + 1, component, candidates, ans, target);
        component.pop_back();
        target += candidates[index];
        while(index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) ++index;
        find_combination(index + 1, component, candidates, ans, target);
        return;
    }
};
