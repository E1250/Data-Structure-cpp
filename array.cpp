#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int length;
    int * items; //pointer name

public:
    Array(int arrSize){
        size = arrSize;
        length=0;
        items = new int [arrSize]; // creating array in heap memory
    }

    void Fill(){
        int no_of_items ;
        cout <<"how many items you want to fill ?\n";
        cin>>no_of_items;
        if (no_of_items >size){
            cout << "you can not exeed the array size\n";
            return;
        }else{
            for (int i=0;i<no_of_items;i++){
                cout <<"enter item no "<< i <<endl;
                cin >>items[i];
                length++;
            }
        }

    }

    void Display(){

        cout<<"Display array content \n";
        for (int i =0 ; i<length ; i++){
            cout <<items[i]<<"\t";
        }
        cout <<endl;
    }

    int getSize(){
        return size;
    }

    int getLength(){
        return length;
    }

    int Search(int key){
        int index = -1;
        for(int i=0;i<length;i++){
            if(items[i]==key){
                index = i;
                break;
            }
        }
        return index;
    }

    void Append(int newItem){
        if(length<size){
            items[length]=newItem;
            length++;
        }else{
            cout <<"Array is full\n";
        }
    }

    void Insert(int index,int newItem){
        if(index >= 0 && index < size){
            for(int i = length ;i>index;i--){
                items[i] = items[i-1];
            }
            items[index]= newItem;
            length++;
        }else{
            cout<<"index out of range ";
        }
    }

    void Delete(int index){
        if(index>=0 && index<size){
            for(int i = index ; i<length-1;i++){
                items[i] = items[i+1];
            }
            length--;
        }else{
            cout<<"index out of array range\n";
        }

        
    }

    void Enlarge(int newSize){
        if(newSize <= size){
            cout<<"nwe size must be larger than current size\n";
            return;
        }else{
            size = newSize;
            int *old =items;
            items= new int[newSize];
            for (int i =0;i<length;i++){
                items[i]=old[i];
            }
            delete[]old;
        }
    }

    void Merge(Array other){
        int newSize = size + other.getSize();
        size = newSize;
        int * old = items;
        items = new int(newSize);
        int i;
        for(i=0;i<length;i++){
            items[i]=old[i];
        }
        delete[]old;
        int j = i;
        for (int i =0;i<other.getLength();i++){
            items[j++]=other.items[i];
            length++;
        }
    }

};

int main(){
    cout << "hello this is Array ADT demo \n";

    int arraySize;
    cout <<"Enter the array size : ";
    cin>>arraySize;
    Array myarray(arraySize);
    myarray.Fill();


    cout <<"Array size = "<<myarray.getSize() << " while length = " << myarray.getLength() << "\n";
    myarray.Display();


     int key;

     int index;
    cout<< "Enter the cvalue to searsh for \n";
    cin>>key;
    index = myarray.Search(key);
    if(index == -1){
        cout << "item not found \n";
    }else{
        cout<<"item found @ position : " << index <<endl;
    }


    cout<<"enter new item to sotre in the array \n";
    int newItem;
    cin>>newItem;
    myarray.Append(newItem);
    myarray.Display();
    
    
    cout<<"enter index and item : ";
    cin>>index ;
    cin>>newItem ;
    myarray.Insert(index,newItem);
    myarray.Display();
    
    cout<<"enter index to delete ";
    cin>>index;
    myarray.Delete(index);
    myarray.Display();
    cout <<"Array size = "<<myarray.getSize() << " while length = " << myarray.getLength() << "\n";

    
    cout<<"enter new size";
    int newSize;
    cin>>newSize;
    myarray.Enlarge(newSize);
    myarray.Display();
    
    Array other(3);
    other.Fill();
    myarray.Merge(other);
    myarray.Display();





    return 0;

}