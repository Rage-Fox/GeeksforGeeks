//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x){
        // Your code here
        stack<char> st;
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : x) {
            if (pairs.count(c)) {
                if (st.empty() || st.top() != pairs.at(c)) {
                    return false;
                }
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends