class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_map<long long,long long>mpp;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                if(target == 0) return true;
                continue;
            }
            if(target%arr[i] == 0){
                long long need = target/arr[i];
                if(mpp.find(need) !=mpp.end()){
                    return true;
                }
            }
            mpp[arr[i]] = i;
        }
        return false;
    }
};