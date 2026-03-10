class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        deque<int>dq;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            while(!dq.empty() && dq.back()>arr[i]){
                dq.pop_back();
            }
            dq.push_back(arr[i]);
            ans+=dq.size();
        }
        return ans;
    }
};