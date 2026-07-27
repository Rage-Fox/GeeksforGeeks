/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    Node * solve(vector<int> & pre, int st, int en){
		if (st>en)
			return NULL;
		if (st == en)
			return new Node(pre[st]);
		Node * res = new Node(pre[st]);
		res->left = solve(pre, st + 1, (st + en)/2);
		res->right = solve(pre, (st + en)/2 + 1, en);
		return res;
	}
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        // code here
        return solve(pre, 0, pre.size() - 1);
    }
};