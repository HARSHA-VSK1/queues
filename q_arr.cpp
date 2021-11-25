
#include <iostream>
using namespace std;
#define MAX 5

template <class T>
class Queue{
    private:
        T *arr;
        int front=-1, rear=-1,size;
    public:
        
        Queue(int s){
            size = s;
            arr = new T[s];
        }
        
        void Ins(T val){
            if(rear == size-1)
                cout << "Queue is full" << endl;
            else{
                if(front==-1)
                    front=0;
                rear++;
                arr[rear] = val;
            }
        }
        
        void Del(){
            if(front==-1 || front>rear)
                cout << "Queue is empty" << endl;
            else{
                cout << "deleted element : ";
                cout << arr[front] << endl;
                front++;
            }
        }
        
        void Display(){
            if(front==-1 || front>rear){
                cout << "Queue is empty" << endl;
            }
            else{
            cout << "Queue elements are:" << endl;
            for(int i =front;i<=rear;i++)
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        
};

int main()
{
    int siz,val,choice,tp;
    cout << "Enter size: ";
    cin >> siz;
    Queue <int> q(siz);
        
    cout << "1.Insert element 2. Delete element 3. Display" << endl;
    while(1){
        cout << "Enter choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.Ins(val);
                break;
            case 2:
                q.Del();
                break;
            case 3:
                q.Display();
                break;
        }
    }
    return 0;
}

