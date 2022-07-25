#include <queue>
#include <iostream>

using namespace std;

int main(){
    queue<int> q[10];
    const int n = 10;
    int arr[n]={200,300,274,55,30,20,44,900};
    int j,divisor = 1;
    for (int i = 1 ; i<=3;i++){
        for(int j=0;j<n ;j++){
            int digit = arr[j]/divisor%10;
            q[digit].push(arr[j]);
        }
        j=0;
        for(int k = 0;k<10;k++){
            while(! q[k].empty()){
                arr[j]=q[k].front();
                q[k].pop();
                j++;
            }
        }
        divisor = divisor*10;
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}