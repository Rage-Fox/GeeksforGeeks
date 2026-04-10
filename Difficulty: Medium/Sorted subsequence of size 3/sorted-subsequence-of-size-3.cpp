class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<int> minPrefix(n);
        minPrefix[0] = arr[0];
        vector<int> maxSuffix(n);
        maxSuffix[n-1] = arr[n-1];
        for (int i=1; i<n; i++) {
            minPrefix[i] = min(arr[i], minPrefix[i-1]);
        }
        for (int i=n-2; i>=0; i--) {
            maxSuffix[i] = max(arr[i], maxSuffix[i+1]);
        }
        for (int i=0; i<n; i++) {
            if (minPrefix[i] < arr[i] && arr[i] < maxSuffix[i]) {
                return {minPrefix[i], arr[i], maxSuffix[i]};
            }
        }
        return {};
    }
};