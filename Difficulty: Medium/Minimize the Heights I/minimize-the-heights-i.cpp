//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        // There should be a boundary between the elements, such that, in the sorted array,
        // the elements on the right side of the boundary will get subtracted by k,
        // while all the elements to the left of it will get increased by k.
        // Consider the boundary to be after 0th element, 1st element, 2nd, 3rd, ...
        // and find out the differences between minimum and maximum elements in modified array.
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mini=arr[0];
        int maxi=arr[n-1];
        int ans=maxi-mini;
        for(int i=1;i<n;i++){
            // consider boundary to be after ith element
            mini=min(arr[0]+k , arr[i]-k);
            maxi=max(arr[i-1]+k ,arr[n-1]-k);
            ans=min(ans,maxi - mini);
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
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends