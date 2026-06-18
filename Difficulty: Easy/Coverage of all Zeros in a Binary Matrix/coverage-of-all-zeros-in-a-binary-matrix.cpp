class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<int> colTotal(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                colTotal[j] += mat[i][j];
            }
        }
        vector<int> colPrefix(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int rowTotal = 0;
            for (int j = 0; j < m; j++) {
                rowTotal += mat[i][j];
            }
            int leftOnes = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    int coverage = 0;
                    if (leftOnes > 0) coverage++;
                    if (rowTotal - leftOnes > 0) coverage++;
                    if (colPrefix[j] > 0) coverage++;
                    if (colTotal[j] - colPrefix[j] > 0) coverage++;
                    ans += coverage;
                } else {
                    leftOnes++;
                }
            }
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    colPrefix[j]++;
                }
            }
        }
        return ans;
    }
};
