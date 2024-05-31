//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        //O(1)
        /*
        01100100=n
        00000110=n>>4
        0110----(8-bit)01000000=n<<4
        0000----(8-bit)11111111=255
        ==============================
        0000----(8-bit)01000000=((n<<4)&255)
        
        ((n<<4)&255)|(n>>4)=01000000|00000110=01000110=70
        */
        int temp=n>>4;
        int temp1=(n<<4)&255;
        return temp1|temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends