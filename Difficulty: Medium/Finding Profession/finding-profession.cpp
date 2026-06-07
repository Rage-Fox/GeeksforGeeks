class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        if(__builtin_popcount(pos-1)&1){
            return "Doctor";
        }
        return "Engineer";
    }
};