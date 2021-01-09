#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList{

    private:
        Node *head;
        int size;

    public:
        LinkedList(){
            head = NULL;
            size = 0;
        }

    void insert_end(int data){

        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }
        else{
            
            Node* node = head;
            while(node->next != NULL){
                node = node->next;
            }
            node->next = temp;
        }

        size += 1;
    }

    void print_list(){

        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    void insert_beginning(int data){
        Node *temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
        size+=1;
    }

    void insert_position(int data, int pos){

        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;

        if(pos==1){
            insert_beginning(data);  
        }
        else if(pos==size+1){
            insert_end(data);
        }
        else{
            Node* ptr = head;
            for(int i = 1; i < pos-1; i++){
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
            size++;
        }   
    }

    void delete_node(int pos){

        Node *temp = new Node();
        temp = head;

        if(pos==1){
            head = temp->next;
            delete temp;
        }
        else{
            for(int i = 1; i < pos-1; i++){
                temp = temp->next;
            }
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
        }
        size--;
    }

    void print_recursion(Node *ptr){


        Node *temp = ptr;
        
        if(temp ==NULL){
            return;
        }
        cout<<temp->data<<" ";
        print_recursion(temp->next);
    }

    int get_size(){
        return size;
    }

    Node* return_head(){
        return head;
    }

    void print_reverse_recursion(Node *ptr){

        Node *temp = ptr;

        if (ptr == NULL){
            return;
        }
        print_reverse_recursion(ptr->next);
        cout<<temp->data<<" ";
    }

    void reverse_list(Node *p){

        if(p->next == NULL){
            head = p;
            return;
        }

        reverse_list(p->next);
        Node* nxt = p->next;
        nxt->next = p;
        p->next = NULL;
    }
};