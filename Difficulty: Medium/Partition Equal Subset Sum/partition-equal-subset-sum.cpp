//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0;
        for(auto &i : arr){
            sum += i;
        }
        if(sum % 2 != 0) return false;
        int sizeOfArr = arr.size();
        int target = sum / 2;
        vector<bool> dp(target + 1, 0);
        dp[0] = true;
        for(int nums : arr){
            for(int i = target; i >= nums; i--) {
                dp[i] = dp[i] || dp[i - nums];
            }
        }
        return dp[target];
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends