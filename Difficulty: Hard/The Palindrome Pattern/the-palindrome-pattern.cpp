//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPal(vector<int> &arr){
        vector<int> v(arr.begin(),arr.end());
        reverse(v.begin(),v.end());
        return v==arr;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size(),m=arr[0].size();
        string ansRow="";
        string ansCol="-1";
        for(int i=0;i<n;i++){
            if(isPal(arr[i])){
                ansRow+=to_string(i)+" R";
                return ansRow;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++) {
                swap(arr[i][j],arr[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            if(isPal(arr[i])){
                ansCol=to_string(i)+" C";
                break;
            }
        }
        return ansCol;
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends