//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n = arr.size();
        vector<int> ans(n);
        int sign = 1;
        if(A < 0) sign = -1;
        for(int k = n - 1, s = 0, e = n - 1; s <= e; k--) {
            int v1 = sign * A * arr[s] * arr[s] + sign * B * arr[s] + sign * C;
            int v2 = sign * A * arr[e] * arr[e] + sign * B * arr[e] + sign * C;
            if(v1 >= v2) ans[k] = v1;
            else ans[k] = v2;
            if(v1 >= v2) s++;
            else e--;
        }
        if(A < 0) {
            reverse(ans.begin(), ans.end());
            for(int i = 0; i < n; i++) ans[i] *= -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends