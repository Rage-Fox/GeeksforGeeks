class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n%k !=0) return false;
        map<int,int> c;
        for(int m : arr){
            c[m]++;
        }
        for(auto it = c.begin();it!= c.end();it++){
            int m = it->first;
            int count = it->second;
            if(count>0){
                for(int i = 0;i<k;i++){
                    if(c[m + i]<count) return false;
                    c[m + i] -= count;
               }
            }
        }
        return true;
    }
};