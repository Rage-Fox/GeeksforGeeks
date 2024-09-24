//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool isValid(vector<int>& curr, vector<int>& target) {
        for(int i = 0; i < 26; i++)
            if(curr[i] < target[i])
                return false;
        return true;
    }
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p){
        // Your code here
        vector<int> req(26);
        for(char ch: p)
            req[ch - 'a']++;
        int st = 0, n = s.size();
        int resLen = n+1, resSt = -1;
        vector<int> curr(26);
        for(int end = 0; end < n; end++) {
            curr[s[end] - 'a']++;
            while(isValid(curr, req)) {
                int len = end - st + 1;
                if(len < resLen) {
                    resLen = len;
                    resSt = st;
                }
                curr[s[st] - 'a']--;
                st++;
            }
        }
        if(resLen > n) return "-1";
        return s.substr(resSt, resLen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends