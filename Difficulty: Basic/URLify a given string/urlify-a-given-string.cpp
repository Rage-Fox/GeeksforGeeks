#include<bits/stdc++.h>
class Solution {
  public:
    string URLify(string &s) {
        // code here
        return regex_replace(s, regex(" "), "%20");
    }
};