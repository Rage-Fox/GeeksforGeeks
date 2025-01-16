//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int N=arr.size();
        for(int i=0;i<N;i++){
            arr[i]=(arr[i]==0?-1:1);
        }
        unordered_map<int,int>map1;
        map1[0]=-1;
        int maxi=0,sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            if(map1.find(sum)!=map1.end()){
                int len=i-map1[sum];
                maxi=max(maxi,len);
            }
            else{
                map1[sum]=i;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends