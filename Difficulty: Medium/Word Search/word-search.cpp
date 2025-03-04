//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int move[5] = {0, 1, 0, -1, 0};
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string &word, int &m, int &n) {
        if(idx == word.size()) return 1;
        char ch = board[i][j];
        board[i][j] = '0';
        bool res = 0;
        for(int k = 0; k < 4; k++) {
            int newI = i + move[k];
            int newJ = j + move[k + 1];
            if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && 
               board[newI][newJ] != '0' && board[newI][newJ] == word[idx]) {
                res |= dfs(newI, newJ, idx + 1, board, word, m, n);
            }
        }
        board[i][j] = ch;
        return res;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(i, j, 1, board, word, m, n)) return 1;
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends