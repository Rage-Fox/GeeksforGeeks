//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int>dq;
        vector<int>ans;
        int i=0,j=0,n=arr.size();
        while(j<n){
            while(dq.size()>0 and arr[dq.front()]<arr[j]){
                dq.pop_front();
            }
            dq.push_front(j);
            if(j-i+1<k){
                j++;
            }
            else{
                ans.push_back(arr[dq.back()]);
                if(i==dq.back()){
                    dq.pop_back();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends