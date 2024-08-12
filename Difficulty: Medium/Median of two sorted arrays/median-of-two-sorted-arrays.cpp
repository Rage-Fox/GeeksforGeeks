//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int>v;
        int i=0,j=0;
        while(i<arr1.size() || j<arr2.size()){
            int a=INT_MAX,b=INT_MAX;
            if(i<arr1.size()) a=arr1[i];
            if(j<arr2.size()) b=arr2[j];
            if(a<b) v.push_back(a),i++;
            else v.push_back(b),j++;
        }
        int n=v.size();
        if(n%2==0) return v[n/2-1]+v[n/2];
        return v[n/2-1];
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends