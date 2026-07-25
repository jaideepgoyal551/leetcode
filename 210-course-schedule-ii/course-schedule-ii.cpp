class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // build - graph
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        vector<int> ans;
        // push all node with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            count++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (count == numCourses) {
            return ans;
        }
        return {};
    }
};