class Solution {
  public:
    void solve(vector<int>&p,int i,int j,vector<int>&ans){
        if(i>j || i>=p.size() || j>=p.size())return;
        if(i == j){ans.push_back(p[i]);return;}
        int start = upper_bound(p.begin()+i+1,p.begin()+j+1,p[i])-p.begin();
        solve(p,i+1,start-1,ans);
        solve(p,start,j,ans);
    }
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        vector<int>ans;
        solve(preorder,0,preorder.size()-1,ans);
        return ans;
    }
};