//Question:- Unique Path III (https://leetcode.com/problems/unique-paths-iii/)
//Level:- Hard
//Prerequisite:- Unique Path I & Path II and BFS 

    int dx[4]={-1,1,0,0}; //used for all 4-adj direction
    int dy[4]={0,0,1,-1}; 
void helper(int i,int j,vector<vector<int>>&grid,int cnt,int& res,int& empty)
{
      if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==-1) return ;
    //if we go out of grid-boundries or it's obstacle then simply return
        if(grid[i][j]==2) 
        {
           if(empty==cnt) res++; //if we reached at target and we passed empty number of cells - this means we passed by every non-obstacle cell.
            return ;
        }
          grid[i][j]=-1; //mark as visited
        for(int k=0;k<4;k++) //call for all 4-adjacent 
        {
          int nx=i+dx[k];
          int ny=j+dy[k];
            helper(nx,ny,grid,cnt+1,res,empty);
        }
         grid[i][j]=0; //backtrack
}

int uniquePathsIII(vector<vector<int>>& grid)
{
        int n=grid.size();//no of row in grid
        int m=grid[0].size();//no of col in grid
        vector<vector<int>>vis(n,vector<int>(m,0));
        int x,y,empty=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(grid[i][j]==1) x=i,y=j; //given there is exactly one starting cell
                else if(grid[i][j]==0) empty++; //count empty cell
            }
        }
        int res=0;
        helper(x,y,grid,0,res,empty);
        return res;
}

