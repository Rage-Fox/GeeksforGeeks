//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        vector<vector<int>> v;
        map<double,vector<int> > mp;
        for (int j = 0; j < points.size();j++) {
            auto i = points[j];
            double k = pow(i[0],2)+pow(i[1],2);
            k = sqrt(k);
            mp[k].push_back(j);
        }
        
        int j = 0;
        int vec = 0;
        for (auto i:mp) {
            while(v.size()!=k && j<i.second.size()) {
                v.push_back(points[i.second[j]]);
                j++;
            }
            j = 0;
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends