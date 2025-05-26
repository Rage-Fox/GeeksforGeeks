/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node *newNode=new Node(data);
        if(!head){
            Node *temp=new Node(data);
            temp->next=temp;
            return temp;
        }
        Node *temp=head;
        int f=0;
        while(temp->next!=head){
            if(temp->data<=data and data<=temp->next->data){
                Node *tempo=temp->next;
                temp->next=newNode;
                newNode->next=tempo;
                f=1;
                break;
            }
            temp=temp->next;
        }
        if(f==0){
            temp->next=newNode;
            newNode->next=head;
        }
        if(newNode->data<head->data){
            head=newNode;
        }
        return head;
    }
};