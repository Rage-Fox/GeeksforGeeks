//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        int mind = INT_MAX;
        int maxd = INT_MIN;
        int num = -1;
        for(int i=1; i<arr.size(); i++){
            int dif = arr[i] - arr[i-1];
            if(dif < mind){
                mind = dif;
            }
            if(dif > maxd){
                maxd = dif;
                num = arr[i];
            }
        }
        if(mind == maxd){
            return arr[n-1] + mind;
        }
        return num - mind;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends