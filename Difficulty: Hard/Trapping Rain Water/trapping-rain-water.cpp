//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> leftMaxBlock(n);
        leftMaxBlock[0]=arr[0];
        for(int i=1;i<n;i++){
           leftMaxBlock[i]=max(leftMaxBlock[i-1],arr[i]);
        }
        vector<int> rightMaxBlock(n);
        rightMaxBlock[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMaxBlock[i]=max(rightMaxBlock[i+1],arr[i]);
        }
        int maximumTrappedWater=0;
        for(int i=0;i<n;i++){
            int currentTrappedWater=min(leftMaxBlock[i],rightMaxBlock[i])-arr[i];
            maximumTrappedWater+=currentTrappedWater;
        }
        return maximumTrappedWater;
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends