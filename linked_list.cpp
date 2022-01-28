#include <iostream>
using namespace std;
 
 class Node{
 public:
    int data;
    Node*next;
 };

 class LinkedList{
public:
    Node *head;
    LinkedList(){
        head = NULL;
    }
     
 bool isEmpty(){
     return (head==NULL);
 }

void insertFirst(int newValue){
    Node * newNode;
    newNode->data= newValue;
    if(isEmpty()){
        newNode->next= NULL;
        head = newNode;
    }else{
        newNode->next=head;
        head = newNode;
    }
}

void display(){
    Node *temp =head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int count(){
    int counter = 0;
    Node *temp =head;
    while(temp !=NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
}

bool isFound(int key){
    bool found = false;
    Node *temp =head;
    while(temp !=NULL){\
        if(temp->data==key){
            found =true;
            break;
        }else{
            temp = temp->next;
        }
        
    }
    return found;
}

void insertBefore(int item, int newValue){

    if(isEmpty()){
        insertFirst(newValue);
    }else{
        if(isFound(item)){
                Node * newNode = new Node();
                newNode->data = newValue;

                Node *temp =head;
                while(temp!=NULL&&temp->next->data!=item){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }else{
                cout<<"item not found \n";
            }
    }
}

void append(int newValue){
    if (isEmpty()){
        insertFirst(newValue);
    }else{
        Node *temp =head;
        while(temp->next!=NULL){
            temp = temp->next;
        } 
        Node *newNode = new Node();
        newNode->data = newValue;
        temp->next = newNode;
        newNode->next = NULL;
    }
}

void Delete (int item){
    if(isEmpty()){
        cout<<"lsit is empty , no item to delete \n";
    }
    // int delValue;
    Node *delPTR = head;
    if (head->data==item){
        head=head->next;
        delete delPTR;
    }else{
        Node *prev =  NULL;
        delPTR = head;

        while (delPTR->data!=item)
        {
            prev = delPTR;
            delPTR = delPTR->next;
        }
        prev = delPTR->next;
        // delValue = delPTR->data;
        delete delPTR;    
    }
    // return delValue;
}






 };
 

 int main(){
     LinkedList list;
     if(list.isEmpty())
        cout<<"the list is empty \n";
     else
        cout<<"List contains "<<list.count()<<endl;
     
    int item; 
    cout<<"enter item to insert in the list \n";
    cin>>item;
    list.insertFirst(item);
    list.display();
    cout<<"List contains "<<list.count()<<endl;

    cout<<"enter item to search for \n";
    cin>>item;
    if(list.isFound(item))
        cout<<"item found\n";
    else
        cout<<"item not found\n";

    int newValue;
    cout<<"enter item and new value to insert \n";
    //cin>>item;
    cin>>newValue;
    //list.insertBefore(item,newValue);
    list.append(newValue);
    list.display();

     cout<<"enter item to delete \n";
    //cin>>item;
    cin>>newValue;
    //list.insertBefore(item,newValue);
    list.Delete(newValue);
    list.display();







 }