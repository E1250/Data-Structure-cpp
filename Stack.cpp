#include <iostream>
using namespace std;

// printing the reverse of a text
// in this way you can create a stack

const int SIZE = 100;
int top = -1;
int elements[SIZE];
 
bool isEmpty(){
    return top==-1;
}
bool isFull(){
    return top==SIZE -1;
}
bool push(int ele){
    if(isFull()){
        return false;
    }else{
        top = top+1;
        elements[top]=ele;
    }
}
int pop(){
    if(isEmpty()){
        return false;
    }else{
        int element = elements[top];
        top = top-1;
        return element;
    }
}

int main(){
    string msg;
    getline(cin,msg);
    for (int i = 0 ; i<msg.length();i++){
        push(msg[i]);
    }
    while (! isEmpty()){
        char ch = pop();
        cout<<ch;
    }

    return 0;
}