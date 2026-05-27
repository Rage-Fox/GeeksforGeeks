class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        map<int,int>mpp;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0')continue;
            mpp[max(i-x,0)]++;
            mpp[i+x+1]--;
        }
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            sum+=mpp[i];
            if(!sum)return false;
        }
        return true;
    }
};