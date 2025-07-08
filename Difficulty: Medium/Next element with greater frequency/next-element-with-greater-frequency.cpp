class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        map<int,int> mp;
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && mp[st.top()]<=mp[arr[i]]){
                st.pop();
            }
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
