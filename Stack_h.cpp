#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 100;
int top = -1;
int elements[SIZE];

bool isEmpty(){
    return top==-1;
}
bool isFull(){
    return top==SIZE -1;
}
bool push(char ele){
    if(isFull()){
        return false;
    }else{
        top = top+1;
        elements[top]=ele;
    }
}
int pop(char &ele){
    if(isEmpty()){
        return false;
    }else{
        int element = elements[top];
        top = top-1;
        return element;
    }
}


int main(){
    push(30);
    push(2.6);
    char ch;
    pop(ch);
    cout<<ch;

    return 0;
}