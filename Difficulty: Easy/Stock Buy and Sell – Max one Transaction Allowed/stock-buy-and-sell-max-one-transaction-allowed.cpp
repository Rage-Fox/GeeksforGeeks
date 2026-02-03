class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int val=0;
        int mx=0;
        for(int i=prices.size()-1;i>=0;i--){
            val=max(val,prices[i]);
            mx=max(mx,val-prices[i]);
        }
        return mx;
    }
};
