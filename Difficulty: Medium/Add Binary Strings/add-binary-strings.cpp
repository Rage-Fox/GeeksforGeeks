//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int mx=max(s1.size(),s2.size());
        while(s1.size()<mx)
            s1="0"+s1;
        while(s2.size()<mx)
            s2="0"+s2;
        int carry=0;
        string ans(mx,'0');
        for(int i=mx-1;i>=0;--i)
        {
            int x=(s1[i]-'0')+(s2[i]-'0')+carry;
            if(x&1)
                ans[i]='1';
            if(x>1)
                carry=1;
            else
                carry=0;
        }
        if(carry)
            ans="1"+ans;
        int ind=0;
        while(ans[ind]=='0')
            ++ind;
        return ans.substr(ind,ans.size()-ind+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends