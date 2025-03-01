//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        int n = s.length();
        stack<string>st;
        string str="";
        int i=0;
        while(i<n){
            if(s[i]==']'){
                string str="";
                int cnt=0;
                while(!st.empty() && st.top()>="a" && st.top()<="z"){
                    string ch = st.top();
                    st.pop();
                    str = ch + str;
                }
                if(!st.empty() && st.top()=="[") st.pop();
                int k=1;
                while(!st.empty() && st.top()>="0" && st.top()<="9"){
                    string ch = st.top();
                    int c = stoi(ch);
                    st.pop();
                    cnt = k*(c) + cnt;
                    k = k*10;
                }
                string final = "";
                for(int i=0;i<cnt;i++) final+=str;
                if(final.length()) st.push(final);
            }
            else{
                string str(1,s[i]);
                st.push(str);
            }
            i++;
        }
        string ans = "";
        while(!st.empty()){
            string str =st.top();
            ans = str+ans;
            st.pop();
        }
        return ans;
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends