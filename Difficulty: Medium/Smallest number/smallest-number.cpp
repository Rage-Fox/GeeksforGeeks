//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(9*d<s)
            return "-1";
        string ans="1";
        ans.append(d-1,'0');
        s--;
        for(int i=d-1;i>=0;i--){
            if(s<9){
                ans[i]='0'+(ans[i]-'0'+s);
                break;
            }
            int k=s-9;
            ans[i]='9';
            s-=9;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends