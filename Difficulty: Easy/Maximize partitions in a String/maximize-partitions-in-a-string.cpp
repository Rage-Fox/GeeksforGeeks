//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
         int n = s.size();
        vector<int> mp(26);
        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a'] = i;
        }
        int ans = 0, ind = 0;
        for (int i = 0; i < n; i++) {
            // Update the farthest last occurrence
            ind = max(ind, mp[s[i] - 'a']);
            // If current index matches the farthest occurrence, make a partition
            if (ind == i) {
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends