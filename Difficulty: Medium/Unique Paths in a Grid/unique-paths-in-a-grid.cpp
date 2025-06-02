class Solution {
  public:
    int n,m;
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(i>=n || j>=m || grid[i][j]==1){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right=0,down=0;
        if(grid[i][j]==0){
            if(i+1<n && grid[i+1][j]==0){
                down=solve(grid,i+1,j,dp);
            }
            if(j+1<m && grid[i][j+1]==0){
                right=solve(grid,i,j+1,dp);
            }
        }
        return dp[i][j]=right+down;
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,0,0,dp);
    }
};