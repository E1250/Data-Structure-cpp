#include <iostream>
using namespace std;


class Node{
    public:
        int data;
        Node * next;

    Node(){
        data=0;
        next=NULL;
    }
};

class Queue{
    public:
    Node *front;
    Node *rear;
    Queue(){
        front = rear = NULL;
    }

    bool isEmpty(){
        if(front == NULL && rear == NULL){
            return true;
        }else{
            return false;
        }

    }
    
    void Enqueue(int item){
        Node * newNode = new Node;
        newNode->data = item;
        if(isEmpty()){
            front = rear = newNode;
        }else{
            rear ->next = newNode;
            rear = newNode;
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty , no items to display \n";
        }else{
            Node *temp = front;
            while(temp!=NULL){
                cout<<temp->data;
                temp = temp->next;
            }
            cout<<endl;
        }

        
    }

    int Dequeue(){
        int delValue= NULL;
        if(isEmpty()){
            cout<<"the queue is empty \n";
        }else if(front == rear){
            delete front;
            front = rear = NULL;
        }else{
            Node *delPTR =front;
            front = front->next;
            delValue = delPTR->data;
            delete delPTR;
        }
        return delValue;
    }

    int getFront(){
        return front->data;
    }

    int getRear(){
        return rear->data;
    }

    int count(){
        int counter = 0;
        Node *temp=front;
        while(temp!=NULL){
            counter++;
            temp =temp->next;
        }
        return counter;
    }

    bool isFound(int item){
        bool found = false;
        Node *temp=front;
        while(temp!=NULL){
            if(temp->data == item){
                found = true;
                temp = temp->next;
            }
        }
        return found;
    }

    void Clear(){
        while(!isEmpty()){
            Dequeue();
        }
    }


};



int main(){

    Queue q;

    for(int i = 1 ; i<=3;i++){
        int item;
        cout<<"enter item to enqueue : ";
        cin>>item;
        q.Enqueue(item);    
    }
    q.display();


    // q.Dequeue();
    // cout<<"after dequque \n";
    // q.display();

    cout<<"Clear all items \n";
    q.Clear();
    cout<<"display after clear \n";
    q.display();


}