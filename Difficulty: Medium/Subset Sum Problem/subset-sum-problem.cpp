//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        for(int i=1; i<n; i++){
            for(int target = 1; target<=sum; target++){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(target >= arr[i]){
                    take = dp[i-1][target - arr[i]];
                }
                dp[i][target] = take | notTake;
            }
        }
        return dp[n-1][sum];
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends