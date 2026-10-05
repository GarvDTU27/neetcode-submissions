class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q ;

        for(int i = 0; i< n ; i++){
            for(int j = 0; j< m ; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        int dx[4] = {0,1,0,-1};
        int dy[4] = {1, 0, -1, 0};
        while(q.size() > 0){
            int x = q.front().first ;
            int y = q.front().second ;
            q.pop();
            int val = grid[x][y];
            vis[x][y] = 0;

            for(int i = 0; i< 4; i++){
                int nx = x + dx[i];
                int ny = dy[i] + y ;

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == INT_MAX ){
                    grid[nx][ny] = val + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
};
