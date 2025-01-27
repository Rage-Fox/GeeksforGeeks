//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    unordered_map<int, Node*> hm;
    int capacity;
    Node* head;
    Node* tail;
    
    void add(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        node->prev = head;
        nextNode->prev = node;
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        this->capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if (hm.find(key) == hm.end())
            return -1;
        Node* node = hm[key];
        remove(node);
        add(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if (hm.find(key) != hm.end()) {
            Node* getNode = hm[key];
            remove(getNode);
        }
        Node* node = new Node(key, value);
        add(node);
        hm[key] = node;

        if (hm.size() > capacity) {
            Node* nodeToDelete = tail->prev;
            hm.erase(nodeToDelete->key);
            remove(nodeToDelete);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends