//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        int n=words.size();
        vector<int> dp(n+1,1);
        unordered_map<string,int> mp;
        auto comp=[](string a,string b){
            return a.size()<b.size();
        };
        sort(words.begin(),words.end(),comp);
        mp.insert({words[0],0});
        for(int i=1;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                string t=words[i];
                t.erase(t.begin()+j);
                if(mp.find(t)!=mp.end()){
                    dp[i]=max(dp[i],1+dp[mp[t]]);
                }
            }
            mp.insert({words[i],i});
        }
        int ans=*max_element(dp.begin(),dp.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends