//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& a) {
        // code here
        int n=a.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)m[a[i]]++;
        int c=0,elem=-1;
        for(auto i:m) {
            if(i.second>c){
                c=i.second;
                elem=i.first;
            }
        }
        return (c>n/2)?elem:-1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends