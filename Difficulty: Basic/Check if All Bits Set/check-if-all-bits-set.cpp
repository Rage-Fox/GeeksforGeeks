class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(!n)return false;
        n++;
        return !(n & (n-1));
    }
};