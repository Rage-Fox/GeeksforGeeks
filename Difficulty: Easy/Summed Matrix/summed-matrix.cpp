//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        // The matrix diagonal will be having maximum occurence equal to the size of the
        // matrix and all other number will have occurence in decreasing manner
        // as we go away from the diagonal
        if(q<2 || q>2*n){
            return 0;
        }
        if(q<=n+1){
            // Decreases from diagonal
            return q-1;
        }
        else{
            // Increases from diagonal but decreases from last element (2*n)
            return 2*n-q+1;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends