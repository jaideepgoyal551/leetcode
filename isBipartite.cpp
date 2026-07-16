#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define fi first
#define se second

#define sz(x) (int)(x).size()

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)

#define yes cout << "YES\n"
#define no cout << "NO\n"

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const int MOD2 = 998244353;



// void solve() {

// }

// int main() {
//     fastio

//     int t;
//     cin >> t;

//     while (t--) {
//         solve();
//     }

//     return 0;
// }

class Solution {
public:
    // DFS function to try coloring the graph
    // node  -> current node
    // c     -> color to assign (0 or 1)
    // color -> stores assigned color of every node
    bool dfs(int node, int c, vector<int>&color, vector<vector<int>>&graph) {
        // Assign the current color to this node
        color[node] = c;

        // Traverse all adjacent nodes
        for (int next : graph[node]) {

            // If the neighbor is not colored yet
            if (color[next] == -1) {

                // If DFS returns false, conflict was found
                if (!dfs(next, 1 - c, color, graph)) {
                    return false;
                }
            }

            // If the neighbor already has the same color
            // then the graph cannot be bipartite
            else if (color[next] == c) {
                return false;
            }
        }
        // No conflict found in this DFS
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // color[i] = -1 -> node not visited
        // color[i] = 0  -> first color
        // color[i] = 1  -> second color
        vector<int>color(n, -1);

        // The graph may have multiple disconnected components,
        // so start DFS from every unvisited node.
        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                // Start coloring this component with color 0
                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }

        // Every component was successfully colored
        return true;

    }
};
