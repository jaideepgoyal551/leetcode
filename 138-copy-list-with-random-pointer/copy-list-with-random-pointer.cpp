/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == NULL){

            return NULL;

        }

        //Insert copied nodes
        Node *temp = head;

        while(temp){

            Node *copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;

        }

        //set random pointers
        temp = head;

        while(temp){

            if(temp ->random){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        //seperate list
        Node *dummy = new Node(0);
        Node *copyTail = dummy;

        temp = head;

        while(temp){
            
            Node *copy = temp->next;
            temp->next = copy->next;
            copyTail->next = copy;
            copyTail = copy;
            temp = temp->next;

        }
        return dummy->next;
    }
};