class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>&grid){
        if(i<0 || i>= grid.size() || j<0 || j>=grid[0].size()){
            return;
        }
        if(grid[i][j]==1){
            grid[i][j]=0;
            dfs(i-1,j,grid);
            dfs(i+1,j,grid);
            dfs(i,j-1,grid);
            dfs(i,j+1,grid);
        }
    }
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 ||i == grid.size()-1 || j==0 || j==grid[0].size()-1){
                    if(grid[i][j]==1)
                        dfs(i,j,grid);
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    c+=1;
                }
            }
        }
        return c;
    }
};