class Solution {
  public:
    int get_ans(int index, int prev, string &s, vector<vector<int>> &dp){
        if(index==(int)s.length())
            return 1;
        if(dp[index][prev]!= -1)
            return dp[index][prev];
        int res= 0;
        int curr=0;
        for(int i = index; i<s.length(); i++){
            curr+= s[i]- '0';
            if(curr>= prev){
                res+=get_ans(i+1, curr, s, dp);
            }
        }
        return dp[index][prev]=res;
    }
    int validGroups(string &s) {
        // code here
        int n= s.length();
        vector<vector<int>> dp(s.length()+1, vector<int> (n*10, -1));
        return get_ans(0, 0, s, dp);
    }
};