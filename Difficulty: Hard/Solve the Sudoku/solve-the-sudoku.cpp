//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution 
{
    public:
    int N;
    bool valid(int i,int j,int x,vector<vector<int>> &grid){
        //same row
        for(int k=0;k<9;k++){
            if(grid[i][k]==x)   return false;
        }
        //same column
        for(int k=0;k<9;k++){
            if(grid[k][j]==x)   return false;
        }
        //current box
        for(int k=0;k<3;k++){
            for(int m=0;m<3;m++){
                int ni = i - i%3 + k;
                int nj = j - j%3 + m;
                if(grid[ni][nj]==x)   return false;
            }
        }
        return true;
    }
    bool solve(int i,int j,vector<vector<int>> &grid){
        if(j==9){
            i++;
            j=0;
        }
        //entire matrix completes at i=8 and j=8
        if(i==9 && j==0)
            return true;
        if(grid[i][j]!=0)
            return solve(i,j+1,grid);
        for(int x=1;x<=9;x++){
            if(valid(i,j,x,grid)){
                grid[i][j]=x;
                if(solve(i,j+1,grid))
                    return true;
                grid[i][j]=0;
            }
        }
        return false;
    }
    //Function to find a solved Sudoku. 
    bool solveSudoku(vector<vector<int>> &grid)
    { 
        // Your code here
        N=grid.size();
        return solve(0,0,grid);
    }
    //Function to print grids of the Sudoku.
    void printGrid (vector<vector<int>> &grid) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};


//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends