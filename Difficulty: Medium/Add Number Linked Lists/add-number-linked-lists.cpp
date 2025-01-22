//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    struct Node* reverseList(struct Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;
        while(curr !=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second){
        // code here
        while(first!= nullptr && first->data ==0){
            first = first->next;
        }
        while(second!= nullptr && second->data ==0){
            second = second->next;
        }
        if(first == nullptr && second == nullptr) {
            Node* newNode =new Node(0);
            return newNode;
        }
        if(first == nullptr|| second == nullptr) {
            return first==nullptr?second:first;
        }
        Node* start1 = reverseList(first);
        Node* start2 = reverseList(second);
        Node* temp1 = start1;
        Node* temp2 = start2;
        Node* newList = NULL;
        Node* temp = NULL;
        int carry = 0;
        while (temp1 != NULL || temp2 != NULL || carry) {
            int sum = carry;
            if (temp1 != NULL) {
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if (temp2 != NULL) {
                sum += temp2->data;
                temp2 = temp2->next;
            }
            carry = sum / 10;
            int digit = sum % 10;
            // create newNode and link it to resulting list
            Node* newNode = new Node(digit);
            if (newList == NULL) {
                newList = newNode;
                temp = newList;
            }
            else {
                temp->next = newNode;
                temp = temp->next;
            }
        }
        return reverseList(newList);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends