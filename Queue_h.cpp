#ifndef CQUEUE_H
#define CQUEUE_H
#include <iostream>
using namespace std;

template<class type,int SIZE>
class CQueue{
    private:
        int r,f;
        type arr[SIZE];
    public:
        CQueue<type,SIZE>(){
            r=f=0;
        }
        bool isEmpty(){return f==r;}
        bool isFull(){return (r+1)%SIZE==f;}
        bool Add(type ele){
            if(isFull()) return false;
            else{
                arr[r]=ele;
                r=(r+1)%SIZE;
                return true;
            }
        }
        bool Remove(type &ele){
            if(isEmpty()) return false;
            else{
                ele =arr[f];
                f= (f+1)%SIZE;
                return true;
            }
        }
};
#endif


int main(){
    CQueue<int,100> q;
    q.Add(5);
    q.Add(9);
    int e;
    q.Remove(e);
    cout<<e;
    q.Remove(e);
    cout<<e;
    return 0;
}

