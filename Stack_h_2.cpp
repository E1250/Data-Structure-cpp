//#ifndef STACH_H
//#define STACH_H

#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

// const int SIZE = 100;
template <class type,int SIZE>
class Stack{
    private:
        int top;
        int elements[SIZE];
    public:
        Stack<type,SIZE>(){
            top=-1;
        }
        //  Stack(){
        //     top=-1;
        // }
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
            elements[++top]=ele;
            return true;
            }
        }
        int pop(char &ele){
            if(isEmpty()){
                return false;
            }else{
                ele = elements[top--];
                return true;
            }
        }
};




int main(){

    Stack<int,100> s1;
    Stack<char,200> s2;

    // push(30);
    // push(2.6);
    // char ch;
    // pop(ch);
    // cout<<ch;

    return 0;
}