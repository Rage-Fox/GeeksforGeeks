class Solution {
  public:
    int dx[8] = {-1,1,-1,1,2,2,-2,-2};
    int dy[8] = { 2,2,-2,-2,1,-1,1,-1};
    int uv = 0;
    int ct = 0;
    bool solve(int str,int stc,int n,vector<vector<int>>&ans){
        if(uv <= 0){
            return true;
        }
        else if(str < 0 || stc < 0  || str >= n || stc >= n || ans[str][stc] != -1){
            return false;
        }
        uv--;
        ans[str][stc] = ct++;
        bool success = false;
        for(int i=0;i<8;i++){
            int x = str+dx[i];
            int y = stc+dy[i];
            success |= solve(x,y,n,ans);
        }
        if(!success){
            uv++;
            ct--;
            ans[str][stc] = -1;
            return false;
        }
        return true;
    }
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>>ans(n,vector<int>(n,-1));
        vector<vector<int>> empty = {{-1}};
        uv = n*n;
        solve(0,0,n,ans);
        return (uv == 0)?ans:empty;
    }
};