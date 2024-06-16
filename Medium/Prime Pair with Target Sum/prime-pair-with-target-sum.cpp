//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        vector<long long int>isPrime(n,1);
        isPrime[0]=0;
        isPrime[1]=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]==1)
                for(int j=2*i;j<n;j+=i)
                    isPrime[j]=0;
        }
        vector<int>ans(2,-1);
        for(int i=1;i<n;i++)
            if(isPrime[i]&&isPrime[n-i])
                return {i,n-i};
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends