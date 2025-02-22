//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& S) {
        // code here
        int open=0,close=0,res=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='(') open++;
            if(S[i]==')') close++;
            if(open==close) res=max(res,open+close);
            if(open<close) open=0,close=0;
        }
        open=0,close=0;
        for(int i=S.length()-1;i>=0;i--){
            if(S[i]=='(') open++;
            if(S[i]==')') close++;
            if(open==close) res=max(res,open+close);
            if(open>close) open=0,close=0;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends