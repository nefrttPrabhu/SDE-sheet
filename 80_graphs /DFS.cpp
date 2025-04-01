class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<int>& ls, vector<int>& vis, int node) {
        vis[node] = 1;
        ls.push_back(node);
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, ls, vis, it);
            }
        }
    }

    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ls;
        vector<int> vis(n, 0);

        int start = 0;
        dfs(adj, ls, vis, start);
        

        return ls;
    }
};

