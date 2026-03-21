class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> ans;
        vector<int> vec = arr;
        sort(vec.begin(), vec.end());
        vector<long long> cat(n + 1, 0);
        cat[0] = cat[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                cat[i] += cat[j] * cat[i - j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
            int left = idx;
            int right = n - idx - 1;
            long long total = cat[left] * cat[right];
            ans.push_back((int)total);
        }
        return ans;
    }
};