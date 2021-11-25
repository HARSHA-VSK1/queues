#include <iostream>
using namespace std;

template <class T>
class node{
    public:
        T data;
        node* next;
};

template <class T>
class Queue{
    public:
        void Ins(int val){
            if(front == NULL){
                front = new node <T> ();
                front->data = val;
            }
            else{
                node <T> *n = new node <T> ();
                n->data = val;
                node <T> *ptr = front;
                while(ptr->next!=NULL){
                    ptr = ptr->next;
                }
                ptr->next = n;
            }
        }

        void Del(){
            if(front==NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                node <T> *temp = front;
                front =front->next;
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
    private:
        node <T> *front = NULL;
};

int main(){
    Queue <int> q;
    q.Ins(11);
    q.Ins(13);
    q.Ins(14);
    q.Display();
    q.Del();
    q.Display();

}