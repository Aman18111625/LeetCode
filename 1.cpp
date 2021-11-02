//Question =>https://leetcode.com/problems/surrounded-regions/ 
//DFS call for check next '0' cell in all the 4-directions.
void dfs(vector<vector<char>>& grid, int i, int j)
{
// If grid[i][j]=='0' ,  mark this cell as '1' which is mean REACHED & make DFS call for upper.lower ,to the left and to the right of current cordinate (i,j). 
    if(grid[i][j] == 'O')
   {
        grid[i][j] = '1';
        if(i+1 < grid.size()) dfs(grid, i+1, j);
        if(i > 1) dfs(grid, i-1, j);
        if(j+1 < grid[i].size()) dfs(grid, i, j+1);
        if(j > 1) dfs(grid, i, j-1);
    }
}
public:
    void solve(vector<vector<char>>& grid) {
       if(grid.empty())//edgecase->if grid is empty so just simply return
            return;

          //number of row in matrix
        int row = grid.size();
        //number of column in matrix
        int col = grid[0].size();
        
//If grid have less than 3 size in any direction: nothing to do, because all cells located on borders this is also a edge case.
     if(row<3 || col<3) return ;
        
        //check for first row and last row
        for(int i=0; i<row; i++){
            dfs(grid, i, 0);
            dfs(grid, i, col-1);
        }
        //Same as above check for first col and last col
    // Since first & last row already checked in previous cycle, skip them here
        for(int j=1; j<col-1; j++){
            dfs(grid, 0, j);
            dfs(grid, row-1, j);
        }
//Go through the whole grid and flip all '1' back into 'O' and all 'O'cell to'X'
// since they're unreacheable from the board located 'O' cell if any
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j] == 'O') grid[i][j] = 'X';
                else if (grid[i][j] == '1') grid[i][j] = 'O';
    }