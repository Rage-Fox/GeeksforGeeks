//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+m);
        int first=accumulate(a,a+n,0);
        int second=accumulate(b,b+m,0);
        int diff=abs(first-second);
        if(diff%2!=0)
            return -1;
        diff=diff/2;
        int i=0,j=0;
        while(i<n && j<m){
            if(abs(a[i]-b[j])==diff)
                return 1;
            else if(abs(a[i]-b[j])>diff){
                if(a[i]<b[j])
                    i++;
                else
                    j++;
            }
            else if(abs(a[i]-b[j])<diff){
                if(a[i]<b[j])
                    j++;
                else
                    i++;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends