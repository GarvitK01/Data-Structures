#include <iostream>

using namespace std;

struct Node{
    Node *next;
    Node *prev;
    int data;
};

class DoublyLinkedList{

    private:
        Node *head;
        int size;

    public:
        DoublyLinkedList(){
            head = NULL;
        }

        void insert_beg(int data){
            Node *temp = new Node();
            temp->data = data;
            temp->next = NULL;
            temp->prev = NULL;

            if(head == NULL){
                cout<<"Inserted as Head"<<endl;
                head = temp;
                return;
            }
           
            head->prev = temp;
            temp->next = head;
            head = temp;
            
        }

        void insert_end(int data){
            Node *temp = new Node();
            temp->data = data;
            temp->next = NULL;
            temp->prev = NULL;

            if(head == NULL){
                cout<<"Inserted as Head"<<endl;
                head = temp;
                return;
            }

            Node *ptr = head;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        } 

        void insert(int data, int pos){

            Node *temp = new Node();
            temp->next = NULL;
            temp->prev = NULL;
            temp->data = data;

            if(head == NULL){
                cout<<"Added as Head"<<endl;
                head = temp;
                return;
            }

            Node *ptr = head;
            for(int i = 0; i < pos-2; i++){
                ptr = ptr->next;
            }

            Node *nxt = ptr->next;
            ptr->next = temp;
            temp->prev = ptr;
            temp->next = nxt;
            nxt->prev = temp;
        }

        void display(){

            Node* ptr = head;
            while(ptr != NULL){
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }

        void delete_end(){

            if(head == NULL){
                cout<<"List is Empty"<<endl;
                return;
            }
            Node *ptr;
            ptr = head;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }

            Node *previous = ptr->prev;
            previous->next = NULL;
            ptr->prev = NULL;
            delete ptr;

        }

        void delte_node(int data){
            
            if (head == NULL){
                cout<<"List is Empty"<<endl;
                return;
            }

            Node *ptr = head;
            while(ptr->data != data){
                ptr = ptr->next;
            }

            Node *previous = ptr->prev;
            Node *nxt = ptr->next;
            previous->next = nxt;
            nxt->prev = previous;
            delete ptr;
        }

        void delete_pos(int pos){

            if(head==NULL){
                cout<<"List is Empty"<<endl;
                return;
            }

            if(pos==1){
                Node *temp = head->next;
                temp->prev = NULL;
                delete head;
                head = temp;
                return;
            }
            
            Node *ptr = head;
            for(int i = 0; i < pos-1; i++){
                ptr = ptr->next;
            }
            Node *previous = ptr->prev;
            Node *nxt = ptr->next;
            previous->next = nxt;
            nxt->prev = previous;
            delete ptr;
        }

        void reverse_recursion(Node *node){

            if(node == NULL){
                cout<<"Empty"<<endl;
                return;
            }

            Node *test = node->prev;

            Node *temp = node->next;
            node->next = node->prev;
            node->prev = temp;

            if(node->prev == NULL){
                head = node;
                return;
            }

            reverse_recursion(node->prev);
        }

        void display_recursion(Node *node){

            if(node == NULL){
                cout<<endl;
                return;
            }

            cout<<node->data<<" ";

            display_recursion(node->next);
        }

        Node *getHead(){
            return head;
        }
};

int main(){

    DoublyLinkedList dll;
    dll.insert_beg(6);
    dll.insert_beg(7);
    dll.insert_beg(8);
    dll.insert_beg(9);
    dll.insert_end(10);
    dll.insert(42, 4);
    dll.display();
    dll.reverse_recursion(dll.getHead());
    cout<<"Reversed List"<<endl;
    dll.display();
    cout<<"Display Recursion"<<endl;
    dll.display_recursion(dll.getHead());
    cout<<"Reverse Again"<<endl;
    dll.reverse_recursion(dll.getHead());
    dll.display_recursion(dll.getHead());
    return 0;
}