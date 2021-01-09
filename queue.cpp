#include "LinkedList.cpp"

class Queue : public LinkedList{

    private:
        Node *front;
        Node *rear;

    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }

        void enqueue(int data){

            Node *temp = new Node();
            temp->next = NULL;
            temp->data = data;

            if(front == NULL && rear == NULL){
                front = temp;
                rear = temp;
                front->next = rear;
                return;
            }
            rear->next = temp;
            rear = temp;
        }

        void dequeue(){
            
            Node *temp = front;
            front = temp->next;
            delete temp;
        }

        void display(){

            Node *temp = front;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main(){

    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(10);
    q.display();
    return 0;
}