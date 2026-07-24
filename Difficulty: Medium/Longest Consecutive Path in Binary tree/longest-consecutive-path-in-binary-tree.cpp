/* Structure of Binary Tree Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};
*/
class Solution {
	public:
	void dfs(Node* root, Node* parent, int len, int &ans) {
		if (!root)
			return;
		if (parent && root->data == parent->data + 1)
			len++;
		else
			len = 1;
		ans = max(ans, len);
		dfs(root->left, root, len, ans);
		dfs(root->right, root, len, ans);
	}
	int longestConsecutive(Node* root) {
		// code here
		if (!root)
			return - 1;
		int ans = 0;
		dfs(root, nullptr, 0, ans);
		return (ans == 1) ? -1 : ans;
	}
};
