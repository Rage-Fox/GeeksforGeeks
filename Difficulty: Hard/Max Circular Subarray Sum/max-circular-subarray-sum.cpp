//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        int n = arr.size();
        int max_sum = arr[0], current_max = arr[0];
        int total_sum = arr[0], min_sum = arr[0], current_min = arr[0];
        for (int i = 1; i < n; i++) {
            current_max = max(arr[i], current_max + arr[i]);
            max_sum = max(max_sum, current_max);
            current_min = min(arr[i], current_min + arr[i]);
            min_sum = min(min_sum, current_min);
            total_sum += arr[i];
        }
        return (total_sum == min_sum) ? max_sum : max(max_sum, total_sum - min_sum);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends