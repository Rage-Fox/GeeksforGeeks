//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        for(auto i:arr){
            if(i!="+" && i != "-" && i !="/" && i!="*"){
                st.push(stoi(i));
            }
            else {
                int s=st.top();
                st.pop();
                int f=st.top();
                st.pop();
                int res;
                if(int(i[0])==43) res=f+s;
                else if(int(i[0])==45) res=f-s;
                else if(int(i[0])==47) res=f/s;
                else if(int(i[0])==42) res=f*s;
                st.push(res);
            }
        }
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends