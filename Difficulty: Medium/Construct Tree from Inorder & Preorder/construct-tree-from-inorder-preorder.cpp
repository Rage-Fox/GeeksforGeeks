//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
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
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
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
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    int findPos(vector<int> &in,int n,int ele){
        for(int i=0;i<n;i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
    }
    Node* solve(vector<int> &in,vector<int> &pre,int &index,int inorderStart,int inorderEnd,int n){
        if(index>=n or inorderStart>inorderEnd){
            return nullptr;
        }
        int ele=pre[index++];
        Node* root=new Node(ele);
        int pos=findPos(in,n,ele);
        root->left=solve(in,pre,index,inorderStart,pos-1,n);
        root->right=solve(in,pre,index,pos+1,inorderEnd,n);
        return root;
    }
    Node *buildTree(vector<int> &in, vector<int> &pre) {
        // code here
        int preorderIndex=0,n=in.size();
        Node* newNode=solve(in,pre,preorderIndex,0,n-1,n);
        return newNode;
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends