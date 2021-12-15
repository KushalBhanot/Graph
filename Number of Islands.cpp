class Solution {
public:
    
    bool isValid(vector<vector<char>>& grid, int i, int j, int rows, int cols, vector<vector<bool>>& vis) {
        return (i >= 0) && (i < rows) && (j >= 0) && (j < cols) && (grid[i][j] == '1' && !vis[i][j]);
    }
    
    void dfs(vector<vector<char>> grid, int i, int j, vector<vector<bool>>& vis) {
        static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1 , 1};
        static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        vis[i][j] = true;
        
        for(int k = 0; k < 8; k++) {
            if(isValid(grid, i + rowNbr[k], j + colNbr[k], grid.size(), grid[0].size(), vis))
                dfs(grid, i + rowNbr[k], j + colNbr[k], vis);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        
        int count = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};
