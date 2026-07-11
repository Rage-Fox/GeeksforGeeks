class Solution {
	public:
	int longestPathDFS(int i, int j, int cost, int xd, int yd, vector<vector<int>> &mat) {
		if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0) {
			return - 1e9;
		}
		if (i == xd && j == yd) {
			return cost;
		}
		mat[i][j] = 0;
		int up = longestPathDFS(i, j - 1, cost + 1, xd, yd, mat);
		int down = longestPathDFS(i, j + 1, cost + 1, xd, yd, mat);
		int left = longestPathDFS(i - 1, j, cost + 1, xd, yd, mat);
		int right = longestPathDFS(i + 1, j, cost + 1, xd, yd, mat);
		mat[i][j] = 1;
		return max({up, down, left, right});
	}
	int longestPath(vector<vector<int>> & mat, int xs, int ys, int xd, int yd) {
		// code here
		if (mat[xs][ys] == 0 || mat[xd][yd] == 0) {
			return - 1;
		}
		int ans = longestPathDFS(xs, ys, 0, xd, yd, mat);
		return (ans < 0) ? -1 : ans;
	}
};
