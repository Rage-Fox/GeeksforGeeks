//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    int vis[6][6];
    string dir="URDL";
    int rr[4]={-1,0,1,0};
    int cc[4]={0,1,0,-1};
    void solve(int r,int c,vector<vector<int>> &m,int n,string &s){
        if(r==n-1 and c==n-1){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<4;i++){
            int nr=r+rr[i];
            int nc=c+cc[i];
            if(nr<n and nc<n and nr>=0 and nc>=0 and !vis[nr][nc] and m[nr][nc]==1){
                s.push_back(dir[i]);
                vis[nr][nc]=1;
                solve(nr,nc,m,n,s);
                s.pop_back();
                vis[nr][nc]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        memset(vis,0,sizeof(vis));
        if(m[0][0]==0){
            return {"-1"};
        }
        vis[0][0]=1;
        solve(0,0,m,n,s);
        if(ans.size()==0){
            return {"-1"};
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends