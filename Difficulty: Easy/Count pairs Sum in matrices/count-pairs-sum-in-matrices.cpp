class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n=mat1.size();
        map<int,int> store;
	    int ans=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            int remain=x-mat1[i][j];
	            store[remain]++;
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(store[mat2[i][j]]>0){
	                ans++;
	                store[mat2[i][j]]--;
	            }
	        }
	    }
	    return ans;
    }
};