//Question: Unique Paths (https://leetcode.com/problems/unique-paths/)
//Difficulty : Medium
//Pre-requisites: Dynamic Programming


//Brute Force:
 //Recursive approach ->give TLE
//Time Complexity: O(2^M*N)  Space Complexity: O(M*N)
    int solve(int i,int j,int m,int n)
    {
        if(i>=m||j>=n)
            return 0;
        if(i==m-1&&j==n-1)
            return 1;
        return solve(i+1,j,m,n)+solve(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }

//Optimal Approach:-
//Recursive + Memoization
//Time Complexity:- O(M*N) Space Complexity:- O(M*N)

  int solve(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>=m||j>=n) return 0;//out of boundaries
        if(i==m-1&&j==n-1) return 1;//reach target
        if(dp[i][j]!=-1)// already calculated
            return dp[i][j];
        
        return dp[i][j]=solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);//calculate & store in DP
    }
    int uniquePaths(int m, int n) {
vector<vector<int>> dp(m,vector<int>(n,-1));//make a dp which will store result against row&col
        return solve(0,0,m,n,dp);
    }