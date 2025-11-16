class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        int m = b.size();
        vector<int> dp(m+1, 0);
        for(int x: a){
            int c=0;
            for(int j=0;j<m;j++){
                if(x == b[j])
                  dp[j] = max(dp[j], c+1);
                else if(x>b[j])
                  c = max(c, dp[j]);
            }
        }
        int ans = dp[0];
        for(int x: dp){
            ans = max(ans, x);
        }
        return ans;
    }
};