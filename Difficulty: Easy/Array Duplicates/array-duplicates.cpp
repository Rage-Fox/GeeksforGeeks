class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int,int> hashset;
        vector<int> res;
        for(auto x:arr){
            hashset[x]++;
        }
        for(auto pair:hashset){
            if(pair.second==2){
                res.push_back(pair.first);
            }
        }
        if(!res.empty()){
            return res;
        }
        else{
            return {};
        }
    }
};