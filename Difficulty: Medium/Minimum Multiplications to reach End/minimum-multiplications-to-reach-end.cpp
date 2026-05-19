class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        vector<int>vis(1000,-1);
        queue<pair<int,int>>q;
        q.push({start,0});
        vis[start]=0;
        while(!q.empty()){
            int temp=q.front().first;
            int step=q.front().second;
            q.pop();
            if(temp==end)
                return step;
            for(auto x:arr){
                int y=(temp*x)%1000;
                // Seeing if this was already visited before in the visited array
                // If not visited, it's default value is 1000
                if(vis[y]==-1){
                    q.push({y,step+1});
                    vis[y]=1+step;
                }
            }
        }
        return -1;
    }
};