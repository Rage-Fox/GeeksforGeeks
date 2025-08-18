class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        int l = 0, r = n + 1;
        while(r > l + 1) {
            int m = (l + r) / 2, cnt = 0;
            for(int i = 0; i < n; i++) cnt += (citations[i] >= m);
            if(cnt >= m) l = m;
            else r = m;
        }
        return l;
    }
};