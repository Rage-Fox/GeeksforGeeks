//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        vector<int>left,right;
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(st.size() && st.top()>=arr[i])
                st.pop();
            if(st.size()==0)
                left.push_back(0);
            else
                left.push_back(st.top());
            st.push(arr[i]);
        }
        while(st.size())
            st.pop();
        for(int i=arr.size()-1;i>=0;i--){
            while(st.size() && st.top()>=arr[i])
                st.pop();
            if(st.size()==0)
                right.push_back(0);
            else
                right.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(right.begin(),right.end());
        int ans = 0;
        for(int i=0;i<arr.size();i++)
            ans = max(ans,abs(left[i]-right[i]));
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends