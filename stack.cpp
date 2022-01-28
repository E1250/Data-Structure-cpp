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


class Stack{
    Node * top;

public:
    Stack(){
        top = NULL;
    }

    bool isEmpty(){
        if(top==NULL){
            return true;
        }else{
            return false;
        }
    }

    void push(int item){

        Node *newNode = new Node();
            newNode->data = item;
        if(isEmpty()){
            newNode->next = NULL; // you can delete this line
            top = newNode;
        }else{
            newNode->next = top;
            top = newNode;

        }
    }

    int pop(){
        if(!isEmpty()){
            int value;
            Node * delPTR = top;
            value = top->data;
            top = top->next;
            delete[]delPTR;
            return value;
        }
    }

    void display(){
        Node *temp = top;
        while(temp!=NULL){
            cout <<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    int peek(){
        return top->data;
    }

    int count(){
        int counter = 0;
        Node *temp = top;
        while(temp!=NULL){
            counter++;
            temp = temp->next;
        }
        cout<<endl;
        return counter;
    }

    bool isFound(int item){
        bool found =false;
        Node *temp = top;
        while(temp!=NULL){
            if (temp->data = item){
                found =true;
            }
            temp = temp->next;
        }
        return found;
    }

    bool isFull(){
        // this is not very important
        Node *ptr =new Node();
        if(ptr == NULL){
            cout<<"the stack is full , cannot add more items";
        }
    }


};
int main(){

    int item;
    Stack s;


    for (int i=0;i<3;i++){
        cout<<"enter item to push\n";
        cin>>item;
        s.push(item);
        s.display();
    }

    cout<<s.pop()<<" was deleted from the stack\n";
    s.display();

    cout <<"enter item to search for \n";
    cin >>item;

    if(s.isFound(item))
        cout<<"is found\n";
    else
        cout<< "not found\n";

    cout<<s.count();
}
