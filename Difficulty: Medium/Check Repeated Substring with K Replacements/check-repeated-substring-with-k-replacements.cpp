class Solution {
	public:
	bool kSubstr(string &s, int k) {
		// code here
		int n = s.size();
		if (n%k!=0)
			return false;
		unordered_map<string, int> um;
		for (int i = 0; i<n; i += k) {
			um[s.substr(i, k)]++;
			if (um.size() > 2)
				return false;
		}
		int c = 0;
		for (auto z: um) {
			if ((z.second)>1)
				c++;
			if (c>1)
				return false;
		}
		return true;
	}
};
