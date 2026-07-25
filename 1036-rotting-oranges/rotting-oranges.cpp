class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size() ;
        int n = grid[0].size() ;

        queue<pair<pair<int, int>, int>> q ;
        int fresh = 0 ;

        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}) ;   // row, col, time
                }
                else if (grid[i][j] == 1) {
                    fresh++ ;
                }
            }
        }

        int dr[4] = {-1, 1, 0, 0} ;
        int dc[4] = {0, 0, -1, 1} ;

        int ans = 0 ;

        while (!q.empty()) {

            int r = q.front().first.first ;
            int c = q.front().first.second ;
            int t = q.front().second ;
            q.pop() ;

            ans = max(ans, t) ;

            for (int k = 0 ; k < 4 ; k++) {

                int nr = r + dr[k] ;
                int nc = c + dc[k] ;

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 2 ;
                    fresh-- ;
                    q.push({{nr, nc}, t + 1}) ;
                }
            }
        }

        if (fresh > 0) {
            return -1 ;
        }

        return ans ;
    }
};