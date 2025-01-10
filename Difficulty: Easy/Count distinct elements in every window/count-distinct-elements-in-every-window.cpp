//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n=arr.size();
        unordered_map<int,int> mp;
        vector<int> res;
        int left=0;
        for(int i=0;i<k;i++){
             mp[arr[i]]++;
        }
       res.push_back(mp.size());
        while(k<n) {
            if(mp[arr[left]]==1){
                 mp.erase(arr[left]);
            }
            else{
                mp[arr[left]]--;
            }
            mp[arr[k]]++;
            res.push_back(mp.size());
            left++;
            k++;
        }
        return res;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends