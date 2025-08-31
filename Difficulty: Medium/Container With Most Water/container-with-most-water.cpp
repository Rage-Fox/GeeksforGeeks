class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> tmp(n, vector<int>(2, 0));
        for(int i = 0; i < n; i++) {
            tmp[i][0] = arr[i]; tmp[i][1] = i;
        }
        sort(tmp.begin(), tmp.end());
        int mini = n, maxi = -1, ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(tmp[i][1] - mini > 0) ans = max(ans, tmp[i][0] * (tmp[i][1] - mini));
            if(maxi - tmp[i][1] > 0) ans = max(ans, tmp[i][0] * (maxi - tmp[i][1]));
            mini = min(mini, tmp[i][1]);
            maxi = max(maxi, tmp[i][1]);
        }
        return ans;
    }
};