class Solution {
  public:
    int optimalKeys(int n) {
        // code here
        if(n<=6)return n;
        vector<long long> dp(n+1,1);
        for(int i=1;i<=6;i++)
            dp[i]=i;
        for(int i=7;i<=n;i++){
            for(int j=i-3;j>0;j--){
                dp[i]=max(dp[i],dp[j]*(i-j-1));
            }
        }
        return dp[n];
    }
};