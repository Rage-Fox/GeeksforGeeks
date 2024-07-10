//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans==0 && mat[i][j]==1)
                    ans=1;
                if(i && j && mat[i][j] && mat[i-1][j-1] && mat[i-1][j] && mat[i][j-1]){
                    mat[i][j]=min({mat[i-1][j-1],mat[i-1][j],mat[i][j-1]})+1;
                    ans=max(ans,mat[i][j]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends