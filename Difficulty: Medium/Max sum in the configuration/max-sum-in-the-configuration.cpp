class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int sum=0;
        int arrsum=0;
        for(int i=0;i<n;i++)
        {
            sum+=i*arr[i];
            arrsum+=arr[i];
        }
        int maxi=sum;
        for(int i=1;i<n;i++)
        {
            sum=sum+arrsum-n*arr[n-i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};