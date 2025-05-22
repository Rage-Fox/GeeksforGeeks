class Solution {
  public:
    int minDeletions(string s) {
        // code here
        // We will use a 2D array dp where dp[i][j] represents
        // the length of the LPS of the substring s[i:j].
        // We initialize the diagonal elements with 1 (since a single character is a palindrome),
        // and then fill the array in a bottom-up manner,
        // updating values based on whether the characters at the current positions match or not.
        // After building the dp array, we can simply subtract the length of the LPS
        // from the total length of the string to get the minimum number of deletions required
        // to form a palindrome.
        int n = s.size();
        string temp = s;
        reverse(temp.begin(), temp.end());
        vector<int> prev(n + 1), curr(n + 1);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == temp[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return n - prev[n];
    }
};