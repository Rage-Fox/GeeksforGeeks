//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int power(int x, int n) {
        long long res = 1;
        int mod=1e9+7;
        while (n > 0) {
            if (n & 1)
                res = (res * 1LL * x) % mod;
            n = n >> 1;
            x = (x * 1LL * x) % mod;
        }
        return res % mod;
    }
    int numberOfConsecutiveOnes(int n) {
        // code here
        int mod=1e9+7;
        if(n==2)
            return 1;
        if(n==3)
            return 3;
        // vector<long long> dp(n+1,0);
        // dp[2] = 1;
        // dp[3] = 3;
        long pp=1,p=3,now;
        for(int i=4;i<=n;i++){
            // dp[i] = (dp[i-1] + pow(2,i-2)%mod + dp[i-2])%mod;
            now=(p+pp+power(2,i-2)%mod)%mod;
            pp=p;
            p=now;
        }
        // return (int)dp[n];
        return (int)p;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends