#include <iostream>
using namespace std;

template <class T>
class node{
    public:
        T data;
        node* next = NULL;
};

template <class T>
class Queue{
    private:
        node <T> *front=NULL;
        node <T> *rear = NULL;
   
    public:
        void Enqueue(T val){
            node <T> *n = new node <T> ();
            n->data = val;
            if(front==NULL && rear==NULL){
                front=rear=n;
            }
            else{
                rear->next = n;
                rear = n;
            }
        }
        
        void Dequeue(){
            if(front==NULL){
                cout << "Queue is empty" << endl;
                return;
            }
            else{
                node <T> *temp = front;
                cout << "Deleted: " << front->data << endl;
                front = front->next;
                delete temp;
            }
        }
       
        void Display(){
            if(front==NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                node <T> *ptr = front;
                while(ptr!=NULL){
                    cout << ptr->data << " ";
                    ptr = ptr->next;
                }
                cout << endl;
            }
        }
};

int main()
{
    int val,choice;
    Queue <int> q;
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
