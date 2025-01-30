//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<int>> &ans,vector<int> &temp,int x,const int n){
        if(x==n){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<n;i++){
            if(check(temp,i)){
                temp.push_back(i);
                dfs(ans,temp,x+1,n);
                temp.pop_back();
            }
        }
    }
    bool check(vector<int> &temp,int x){
        int n=temp.size();
        bool ans=1;
        for(int i=0;i<n;i++){
            if(temp[i]==x || temp[i]-i+n==x || temp[i]+i-n==x){
                ans=0;
                break;
            }
        }
        return ans;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(ans,temp,0,n);
        for(auto &v:ans)
            for(auto &x:v)
                x++;
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

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends