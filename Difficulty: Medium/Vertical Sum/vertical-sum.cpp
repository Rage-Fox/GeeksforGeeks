/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        map<int,int> mp;
        queue<pair<int,Node*>> q;
        q.push({0,root});
        while(!q.empty()){
            int x = q.front().first;
            Node* node = q.front().second;
            q.pop();
            mp[x] += node->data;
            if(node->left){
                q.push({x-1,node->left});
            }
            if(node->right){
                q.push({x+1,node->right});
            }
        }
        vector<int> ans;
        for(auto &it : mp)
            ans.push_back(it.second);
        return ans;
    }
};