/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node*root,unordered_map<Node*,vector<Node*>>&omap,Node*parent) {
        if(root==NULL) {
            return;
        }
        inorder(root->left,omap,root);
        if(root->left) {
            omap[root].push_back(root->left);
        }
        if(root->right) {
            omap[root].push_back(root->right);
        }
        if(parent) {
            omap[root].push_back(parent);
        }
        inorder(root->right,omap,root);
    }
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,vector<Node*>>omap;
        inorder(root,omap,NULL);
        unordered_map<Node*,bool>visited;
        Node* finders=NULL;
        for(auto i:omap) {
            if(i.first->data==target) {
                finders=i.first;
            }
            visited[i.first]=false;
        }
        queue<Node*>q;
        q.push(finders);
        visited[finders]=true;
        int count=0;
        while(!q.empty()) {
            count++;
            int counter=q.size();
            for(int i=0;i<counter;i++) {
                Node* vertex=q.front();
                q.pop();
                vector<Node*>sides=omap[vertex];
                for(int j=0;j<sides.size();j++) {
                    if(!visited[sides[j]]) {
                        visited[sides[j]]=true;
                        q.push(sides[j]);
                    }
                }
            }
        }
        return count-1;
    }
};