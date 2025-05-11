//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        vector<int> presum;
        int sum=arr[0];
        presum.push_back(arr[0]);
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(sum);
        for(int i=1;i<arr.size();i++){
            sum+=arr[i];
            presum.push_back(sum);
            pq.push(sum);
            if(pq.size()>k)pq.pop();
            for(int j=0;j<i;j++){
                pq.push(presum[i]-presum[j]);
                if(pq.size()>k)pq.pop();
            }
        }
        return pq.top();
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends