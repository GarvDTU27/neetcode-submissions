class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0 , -1, 0};
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &vis, int &count){
        count++ ;
        vis[i][j] = 1;
        int n = vis.size();
        int m = vis[0].size();
        for(int k = 0; k< 4; k++){
            int nx = dx[k] + i ;
            int ny = dy[k] + j ;

            if(nx < n && nx >= 0 && ny >= 0 && ny < m && vis[nx][ny] == 0 && grid[nx][ny] == 1){
                dfs(grid, nx, ny, vis, count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int maxCount = 0;

        for(int i = 0; i< n ; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int count = 0;
                    dfs(grid, i, j, vis, count);
                    maxCount = max(count,maxCount);
                }
            }
        }

        return maxCount ;
    }
};
