//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        vector<string> v;
        string s = "";
        for(int i=0; i<str.size(); i++){
            if(str[i]!='.'){
                s = s + str[i];
            }
            else{
                v.push_back(s);
                s= "";
            }
        }
        v.push_back(s);
        s = "";
        for(int i=v.size()-1 ; i>=0; i--){
            s = s + v[i];
            if(i!=0){
                s = s + '.';
            }
        }
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
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends