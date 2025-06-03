class Solution {
  public:
    long long int solve(string &str, int n, int k){
        // intially windows size
        int i = 0, j = 0;
        long long int ans = 0;
        long long int dist = 0;
        int hash_cnt[26] = {0};
        while (j < n){
            hash_cnt[str[j] - 'a']++;
            if (hash_cnt[str[j] - 'a'] == 1)
                dist++;
            // decrease the size of window
            while (dist > k){
                hash_cnt[str[i] - 'a']--;
                if (hash_cnt[str[i] - 'a'] == 0)
                    dist--;
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here.
        int n = s.size();
        // The main condition now is to get exactly k unique characters
        // so you need to remove the count of substrings with atmost k-1 characters from k characters ones
        // and thats represented by function calcCount(s,k) - calcCount(s,k-1)
        return solve(s, n, k) - solve(s, n, k - 1);
    }
};