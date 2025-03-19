//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int help(vector<int> &a,int n,int k,int i,int buy,vector<vector<vector<int>>>& memo){
        if(i>=n or k<0) return 0;
        if(memo[i][k][buy]!=-1) return memo[i][k][buy];
        int sell=0,brought=0;
        if(buy){
            sell = max(a[i]+help(a,n,k,i+1,0,memo),help(a,n,k,i+1,1,memo));
        }
        else{
            brought = max(-a[i]+help(a,n,k-1,i+1,1,memo),help(a,n,k,i+1,0,memo));
        }
        return memo[i][k][buy] = max({sell,brought});
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();     
        vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(k+1,vector<int>(3,-1)));
        return help(prices,n,k,0,0,memo);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends