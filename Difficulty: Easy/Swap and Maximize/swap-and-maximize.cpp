//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int> temp;
        int i=0,j=arr.size()-1;
        while(i<=j){
            temp.push_back(arr[i++]);
            if(i>j)
                break;
            temp.push_back(arr[j--]);
        }
        long long ans=0;
        for(int i=1;i<temp.size();i++){
            ans+=abs(temp[i]-temp[i-1]);
        }
        ans+=abs(temp[0]-temp[temp.size()-1]);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends