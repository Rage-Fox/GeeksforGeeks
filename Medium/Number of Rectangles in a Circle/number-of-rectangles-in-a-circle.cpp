//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        // For a rectange to be fitted in a circle,
        // its diagonal should less than or equal to the diameter of the circle (2r).
        // a^2 + b^2 <= (2r)^2
        int d=2*r;
        if(r==1){
            return 1;
        }
        int rectangles=0;
        for(int i=1;i<d;i++){
            for(int j=1;j<d;j++){
                if((i*i)+(j*j)<=4*r*r){
                    rectangles++;
                }
            }
        }
        return rectangles;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends