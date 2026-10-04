class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0 , -1, 0};
    void bfs(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &vis){
        vis[i][j] = 1;
        int n = vis.size();
        int m = vis[0].size();
        for(int k = 0; k< 4; k++){
            int nx = dx[k] + i ;
            int ny = dy[k] + j ;

            if(nx < n && nx >= 0 && ny >= 0 && ny < m && vis[nx][ny] == 0 && grid[nx][ny] == '1'){
                bfs(grid, nx, ny, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int count = 0;

        for(int i = 0; i< n ; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    count++ ;
                    bfs(grid, i, j, vis);
                }
            }
        }

        return count ;
    }
};
