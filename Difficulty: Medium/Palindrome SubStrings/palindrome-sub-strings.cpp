//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int ans = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            for (int x : {0, 1}) {
                int l = i, r = i + x;
                while (0 <= l and r < n and s[l] == s[r])
                    ans++, l--, r++;
            }
        }
        return ans - s.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends