class Solution {
	public:
	int minSubsets(vector<int>& arr) {
		// code here
		int ans = 0;
		unordered_map<long long int, int> m;
		for (auto el : arr)
			m[el] = 1;
		for (int i = 0; i<arr.size(); i++) {
			if (m[arr[i]] == 1 && !m[arr[i]-1])
				ans++;
		}
		return ans;
	}
};
