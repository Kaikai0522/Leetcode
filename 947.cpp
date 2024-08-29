class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        parent.resize(n);
        for(int i = 0;i < n;++i)
            parent[i] = i;
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    _union(i, j);

        unordered_set<int> p;
        for(int i = 0;i < n;++i)
            p.insert(find_parent(parent[i]));
        return n - p.size();
    }
    int find_parent(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_parent(parent[x]);
    }
    void _union(int x, int y){
        int parent_x = find_parent(x), parent_y = find_parent(y);
        if(parent_x == parent_y) return;
        if(parent_x < parent_y) parent[parent_y] = parent[parent_x];
        parent[parent_x] = parent[parent_y];
        return;
    }
    vector<int> parent;
};
