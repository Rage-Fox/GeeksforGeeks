class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(long long i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        long long cost=0;
        while(pq.size()!=1){
            long long ele1=pq.top();
            pq.pop();
            long long ele2=pq.top();
            pq.pop();
            pq.push(ele1+ele2);
            cost+=ele1+ele2;
        }
        return cost;
    }
};