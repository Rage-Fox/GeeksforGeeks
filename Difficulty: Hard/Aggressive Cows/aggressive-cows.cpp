//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool solvable(int mid,int n,vector<int> &stalls,int k){
        int prev=stalls[0],count=1;
        for(int i=1;i<n;i++){
            if(stalls[i]-prev>=mid){
                count++;
                prev=stalls[i];
            }
            if(count==k){
                return true;
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int i=1,j=stalls[n-1]-stalls[0],ans=1;
        while(i<=j){
            int mid=(i+j)/2;
            if(solvable(mid,n,stalls,k)){
                ans=max(ans,mid);
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends