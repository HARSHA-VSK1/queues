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
        
        T Dequeue(){
            if(front==NULL){
                cout << "Queue is empty" << endl;
                return 0;
            }
            else{
                node <T> *temp = front;
                front = front->next;
                return temp->data;
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

        bool isempty(){
            if(front==NULL)
                return true;
            else
                return false;
        }
};