//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &a) {
        // code here
        int R=a.size(),C=a[0].size();
        int startR = 0,startC = 0,endR = R-1,endC = C-1,cnt = 0,total = R * C;
        vector<int> ans;
        while(cnt < total)
        {
            for(int idx = startC; cnt < total and idx <= endC; idx++){
                ans.push_back(a[startR][idx]);
                cnt++;
            }
            startR++;
            for(int idx = startR; cnt < total and idx <= endR; idx++){
                ans.push_back(a[idx][endC]);
                cnt++;
            }
            endC--;
            for(int idx = endC; cnt < total and idx >= startC; idx--){
                ans.push_back(a[endR][idx]);
                cnt++;
            }
            endR--;
            for(int idx = endR; cnt < total and idx >= startR; idx--){
                ans.push_back(a[idx][startC]);
                cnt++;
            }
            startC++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends