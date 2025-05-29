/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    pair<int,int>helper(Node*root,pair<int,int>temp){
        if(root==NULL){
            return temp;
        }
        pair<int,int>lans=helper(root->left,{temp.first+1,temp.second+root->data});
        pair<int,int>rans=helper(root->right,{temp.first+1,temp.second+root->data});
        if(lans.first==rans.first){
            if(lans.second>rans.second)return lans;
            else return rans;
        }
        if(lans.first>rans.first)return lans;
        else return rans;
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        pair<int,int>ans=helper(root,{0,0});
        return ans.second;
    }
};