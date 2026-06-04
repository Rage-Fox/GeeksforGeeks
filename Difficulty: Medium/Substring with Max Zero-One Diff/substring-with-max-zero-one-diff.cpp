class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int maxSum = -1;
        int currentSum = 0;
        for(char ch : s) {
            int value = (ch == '0') ? 1 : -1;
            currentSum += value;
            maxSum = max(maxSum, currentSum);
            if(currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};