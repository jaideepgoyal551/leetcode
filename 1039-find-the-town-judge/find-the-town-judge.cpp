class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {

        // indegree[i] = how many people trust i
        vector<int> indegree(n + 1, 0);

        // outdegree[i] = how many people i trusts
        vector<int> outdegree(n + 1, 0);

        // Process every trust relation
        for (auto edge : trust) {

            int u = edge[0];
            int v = edge[1];

            // u trusts someone
            outdegree[u]++;

            // v is trusted by someone
            indegree[v]++;
        }

        // Check every person
        for (int i = 1; i <= n; i++) {

            // Judge trusts nobody
            // and everyone trusts judge
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        // Judge does not exist
        return -1;
    }
};