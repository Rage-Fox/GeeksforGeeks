//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int,int> index_map;
        int max_distance=0;
        for(int i=0;i<arr.size();i++){
            if(index_map.find(arr[i])!=index_map.end()){
                int distance=i-index_map[arr[i]];
                max_distance=max(max_distance,distance);
            }
            else{
                index_map[arr[i]]=i;
            }
        }
        return max_distance;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends