#include <iostream>
using namespace std;

// should not be ordered 
//  it is bad code


int Linear_Search(int arr[],int n,int key){

    for (int i=1;i<=n-1;i++){
        if(key == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){

    int a[]= {5,9,2,3,4,7,6,10,20,30}; // the array
    int n = 10; //size of the array
    int key = 6; //number i am searching about
    int index = Linear_Search(a,n,key);
    if(index >= 0){
        cout<<"Found at location "<<index ;
    }
    else{
        cout<<"not found";
    }

    return 0;
}