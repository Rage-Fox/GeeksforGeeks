//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int cnt = 0;
        int n = arr.size();
        for(int i = 0 ; i <  n ; i++){
            int mini = i;
            for(int j = i + 1 ; j < n ;j++){
                if(arr[j] < arr[mini]){
                    mini = j;
                }
            }
            if(arr[i] != arr[mini]){
                swap(arr[i] , arr[mini]);
                cnt++;
            }
            if(cnt > 2) break;
        }
        if(cnt <= 2) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends