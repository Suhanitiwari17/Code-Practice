/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* curr=head;
        while(curr!=NULL){
            if(curr->child!=NULL){
                Node* next=curr->next;
                curr->next=flatten(curr->child);

                curr->next->prev = curr;
                curr->child=NULL;

                //find a tail
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                //attach tail with next ptr
                if(next!=NULL){
                    curr->next=next;
                    next->prev=curr;
                }
            }
            curr=curr->next;
        }
        return head;
    }
};