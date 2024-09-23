//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>ans;
        int ans1=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                ans.push_back(arr[i]);
            }
             ans1=ans1^arr[i];
        }
        ans1=ans1^ans[0];
        for(int i=1;i<=n;i++){
            ans1=ans1^i;
        }
        ans.push_back(ans1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends