#include <iostream>
using namespace std;
#include "q_header.h"

void Count(int arr[], int n, int rad){
    Queue <int> q[10];
    for(int i=0;i<n;i++){
        q[(arr[i]/rad)%10].Enqueue(arr[i]);
    }
    int p=0;
    for(int i=0;i<10;i++){
        while(!q[i].isempty()){
            arr[p] = q[i].Dequeue();
            p++;
        }
    }
}

void RadixSort(int arr[], int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i])
            max = arr[i];
    }
    int q = 1;
    while (max>0)
    {
        Count(arr,n,q);
        q*=10;
        max/=q;
    }
    
}

int main(){
    int size,val;
    cout << "Enter size: ";
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout << "Value: ";
        cin >> val;
        arr[i] = val;
    }
    RadixSort(arr,size);
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
