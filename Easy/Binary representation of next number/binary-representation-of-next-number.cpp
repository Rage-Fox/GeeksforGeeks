//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        // its same as add 1 to our string
        int n=s.length();
        int i=n-1;
        while(i>=0 && s[i]=='1'){
            s[i]='0';
            i--;
        }
        if(i>=0 && s[i]=='0'){
            s[i]='1';
        }
        else{
            s='1'+s;
        }
        // remove extra zeroes at start
        s.erase(0, s.find_first_not_of('0'));
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends