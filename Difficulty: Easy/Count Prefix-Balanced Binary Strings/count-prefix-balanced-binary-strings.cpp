class Solution {
  public:
    int prefixStrings(int n) {
        // code here
        int mod=1e9+7;
        vector<long long int> dp(n+1, 0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++){
           int l=0,r=i-1;
           while(l<i && r>=0){
             (dp[i]+=((dp[l]%mod)*(dp[r]%mod))%mod)%mod;
             l++; r--;
           }

        }
        return dp[n]%mod;
    }
};