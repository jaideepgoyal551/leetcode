class Solution {
public:
    void dfs(int node, vector<vector<int>>& g, vector<int>& vis) {
        vis[node] = 1;
        for (int s : g[node]) {

            if (vis[s] == 0) {
                dfs(s, g, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        vector<vector<int>> g(n);

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> vis(n, 0);

        dfs(source, g, vis);
        return vis[destination];
    }
};