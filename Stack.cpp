#include "LinkedList.cpp"

class Stack : public LinkedList{

    private:
        Node *top;

    public: 
        Stack(){
            top = NULL;
        }

        void push(int data){

            Node *temp = new Node();
            temp->data = data;
            temp->next = top;
            top = temp; 
        }

        void pop(){

            if(top == NULL){
                cout<<"Empty List"<<endl;
                return;
            }

            Node *temp = top;
            top = top->next;
            delete temp;
            
        }

        void display(){
            
            Node *temp = top;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};

int main(){

    Stack stack;
    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(7);
    stack.push(9);
    stack.display();
    return 0;
}