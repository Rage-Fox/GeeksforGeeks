//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n,m;
    void solve(int i,int j,vector<vector<char>>&grid){
        if(i>=n || i<0 || j<0 || j>=m || grid[i][j]=='W'){
            return;
        }
        grid[i][j]='W';
        solve(i-1,j,grid);
        solve(i,j-1,grid);
        solve(i+1,j,grid);
        solve(i,j+1,grid);
        solve(i-1,j+1,grid);
        solve(i+1,j-1,grid);
        solve(i+1,j+1,grid);
        solve(i-1,j-1,grid);
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!='W'){
                    count++;
                    solve(i,j,grid);
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends