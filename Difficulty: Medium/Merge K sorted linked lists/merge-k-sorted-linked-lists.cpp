//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node *merge(Node *l1,Node *l2){
        Node *dummy=new Node(0);
        Node *res=dummy;
        while(l1!=NULL &&l2!=NULL){
            if(l1->data<=l2->data){
                res->next=l1;
                l1=l1->next;
            }
            else{
                res->next=l2;
                l2=l2->next;
            }
            res=res->next;
        }
        if(l1!=NULL){
            res->next=l1;
        }
        if(l2!=NULL){
            res->next=l2;
        }
        return dummy->next;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if(arr.empty()) return NULL;
        for(int i=1;i<arr.size();i++){
            arr[i]=merge(arr[i],arr[i-1]);
        }
        return arr.back();
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends