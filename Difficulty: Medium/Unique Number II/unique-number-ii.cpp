//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& nums) {
        // Code here.
        int result = 0;
        for(auto it : nums){
            result ^=it;
        }
        int i;
        for(i=0;i<32;i++){
            if((result>>i)&1){
                break;
            }
        }
        int first = 0, second=0;
        for(auto it : nums){
            if((it>>i)&1){
                first ^=it;
            }
            else{
                second ^=it;
            }
        }
        vector<int>vec;
        if(first<second){
            vec.push_back(first);
            vec.push_back(second);
        }
        else{
            vec.push_back(second);
            vec.push_back(first);
        }
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends