class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        // Shouldn't be a power of 2
        return (n&(n-1))!=0;
    }
};