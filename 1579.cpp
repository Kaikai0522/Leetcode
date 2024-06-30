class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> t_three_parents(n + 1);
        for(int i = 0;i <= n;++i)
            t_three_parents[i] = i;
        sort(edges.begin(), edges.end());
        int ans = 0, i = edges.size() - 1;
        // use type 3 first, and if there is cycle, ans += 1
        for(;i >= 0 && edges[i][0] == 3;--i){
            bool connect_success = _union(t_three_parents, edges[i][1], edges[i][2]);
            if(!connect_success) ++ans;
        }
        vector<int> t_one_parents(t_three_parents.begin(), t_three_parents.end()), t_two_parents(t_three_parents.begin(), t_three_parents.end());
        for(;i >= 0 && edges[i][0] == 2;--i){
            bool connect_success = _union(t_two_parents, edges[i][1], edges[i][2]);
            if(!connect_success) ++ans;
        }
        for(;i >= 0 && edges[i][0] == 1;--i){
            bool connect_success = _union(t_one_parents, edges[i][1], edges[i][2]);
            if(!connect_success) ++ans;
        }
        // checking fully connected
        int one_parent = find_parent(t_one_parents, 1), two_parent = find_parent(t_two_parents, 1);
        for(int i = 2;i <= n;++i)
            if(one_parent != find_parent(t_one_parents, i) || two_parent != find_parent(t_two_parents, i))
                return -1;
        
        return ans;
    }
private:
    // return true for connect success; false for already connected
    bool _union(vector<int> &parent, int a, int b){
        int parent_a = find_parent(parent, a), parent_b = find_parent(parent, b);
        if(parent_a == parent_b)
            return false;
        if(a < b) parent[parent_b] = parent_a;
        else parent[parent_a] = parent_b;
        return true;
    }
    int find_parent(vector<int> &parent, int a){
        if(parent[a] == a) return a;
        return parent[a] = find_parent(parent, parent[a]);
    }
};
