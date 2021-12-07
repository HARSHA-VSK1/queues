#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class Queue{
    private:
        T *arr;
        int front=-1,rare=-1;
        int size=0;
    public:
        Queue(int s){
            size = s;
            arr = new T[size];
        }

        void PushRare(int val){
            if(rare==size-1)
                cout << "Queue is full" << endl;
            else{
                if(front==-1)
                    front++;
                arr[++rare] = val;
            }
        }

        void DelFirst(){
            if(front==-1 || front > rare){
                cout << "Queue is empty" << endl;
            }
            else{
                cout << "Deleted element: " << arr[front] << endl;
                front++;
            }
        }

        void DelEnd(){
            if(front==-1 || front > rare)
                cout << "Queue is empty" << endl;
            else{
                cout << "Deleted element: " << arr[rare] << endl;
                rare--;
            }
        }

        void PushFront(T val){
            if(front==-1){
                front = 0;
                rare = 0;
            }
            else if(front==0){
                front = size-1;
            }
            else   
                front-=1;
            arr[front] = val;
        }

};
int main(){
    
    return 0;
}
