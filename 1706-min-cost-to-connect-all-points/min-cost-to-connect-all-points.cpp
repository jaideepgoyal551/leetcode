class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size() ;

        // dis[i] = Minimum cost to connect point i
        // with our currently formed MST
        vector<int> dis(n , INT_MAX) ;

        // vis[i] = 1 means point i is already included in MST
        vector<int> vis(n , 0) ;

        // Starting from point 0
        // Cost to include starting point is 0
        dis[0] = 0 ;

        int ans = 0 ;

        // We need to include all n points in MST
        for(int i = 0 ; i < n ; i++) {

            int node = -1 ;

            // Step 1: Find the unvisited point
            // having minimum connection cost
            for(int j = 0 ; j < n ; j++) {

                if(!vis[j] && (node == -1 || dis[j] < dis[node])) {
                    node = j ;
                }
            }

            // Step 2: Include this point in MST
            vis[node] = 1 ;

            // Add its minimum connection cost to answer
            ans += dis[node] ;

            // Step 3: Update minimum distances
            // of all remaining unvisited points
            for(int j = 0 ; j < n ; j++) {

                if(!vis[j]) {

                    // Calculate Manhattan distance
                    // between selected point and current point
                    int cost = abs(points[node][0] - points[j][0]) + abs(points[node][1] - points[j][1]) ;

                    // Update only if we found a cheaper connection
                    dis[j] = min(dis[j] , cost) ;
                }
            }
        }

        return ans ;
    }
};