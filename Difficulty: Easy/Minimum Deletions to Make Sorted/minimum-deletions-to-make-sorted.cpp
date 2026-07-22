class Solution {
  public:
    int minDeletions(vector<int>& a) {
        // code here
        vector<int> prev;
        int n=a.size();
        prev.push_back(a[0]);
        for(int i=1;i<n;i++){
            if( prev.back() <a[i] ){
                prev.push_back(a[i]);
            }
            else{
                auto x = lower_bound(prev.begin(), prev.end(), a[i]);
                *x= a[i];
            }
        }
        return n-prev.size();
    }
};