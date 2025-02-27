//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int>st;
    int minEle;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(!st.size()) {
            minEle=x;
            st.push(x);
        } else if(x<minEle) {
            st.push(x-minEle);
            minEle=x;
        } else st.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st.size()) return;
        if(st.top()<minEle) minEle-=st.top();
        st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st.size()) return -1;
        if(st.top()<minEle) return minEle;
        return st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!st.size()) return -1;
        return minEle;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends