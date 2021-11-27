#include <iostream>
using namespace std;

template <class T>
class Queue{
    private:
        T *arr;
        int front = -1, rear=-1, size;

    public:
    
        Queue(int s){
            size = s;
            arr = new T[s];
        }

        void Enqueue(int val){
            if(front==(rear+1)%size){
                cout << "Queue is full " << endl;
            }
            else{
                if(front==-1)
                    front++;
                rear = (rear+1)%size;
                arr[rear] = val;
            }
        }
       
        void Dequeue(){
            if(front==-1)
                cout << "stack is empty";
            else{
                cout << "deleted element: " << arr[front] << endl;
                if(front==rear)
                    front=rear=-1;
                else
                    front = (front+1)%size;
            }
        }
       
        void Display(){
            if(front==-1)
                cout << "Queue is empty " << endl;
            else{
                cout << "Queue elements are: " << endl;
                int i=front;
                while(i!=rear){
                    cout << arr[i] << " ";
                    i = (i+1)%size;
               }
                cout << arr[i] << endl;
            }
        }
};

int main(){
    int siz,val,choice;
    cout << "Enter size: ";
    cin >> siz;
    Queue <int> q(siz);
    cout << "1. Insert element 2. Delete element 3. Display" << endl;
    while(1){
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            q.Enqueue(val);
            break;
       
        case 2:
            q.Dequeue();
            break;
       
        case 3:
            q.Display();
            break;
        default:
            break;
        }
    }
    return 0;
}
