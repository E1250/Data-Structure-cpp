#include <iostream>
using namespace std;

// should be ordered 
//  it is good code


int Binay_Search(int a[],int n,int key){

    int l = 0; // low
    int h = n-1; // high
    int m; // mid

    while (l<=h){
        m = (l+h)/2;
        if(key== a[m]){
            return m;
        }else if(key >a[m]){
            l = m+1;
        }else{
            h=m-1;
        }
    }
    return -1;
}

int main(){

    int a[]= {3,5,9,14,15,20,25,30,34,36}; // the array
    int key = 25; //number i am searching about
    int index = Binay_Search(a,10,key); // 10 is the size
    if(index == -1){    
        cout<<"not found";
    }
    else{
        cout<<"Found at location "<<index ;
    }
    return 0;
}