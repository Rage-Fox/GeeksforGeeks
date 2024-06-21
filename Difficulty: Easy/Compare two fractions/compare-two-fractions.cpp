//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        // Code here
        int a[4]={0,0,0,0},n=str.length(),j=0;
        string ans;
        for(int i=0;i<n;i++){
            if(str[i]==' ')
                continue;
            if(str[i]==',')
                j++;
            else if(str[i]=='/')
                j++;
            else{
                a[j]=10*a[j]+(str[i]-'0');
            }
        }
        float x=(float)a[0]/a[1];
        float y=(float)a[2]/a[3];
        if(x==y){
            ans = "equal";
        }
        else if(x>y){
            ans=to_string(a[0]);
            ans+='/';
            ans+=to_string(a[1]);
        }
        else{
            ans=to_string(a[2]);
            ans+='/';
            ans+=to_string(a[3]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends