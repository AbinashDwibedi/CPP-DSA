#include<iostream>

class Queue{
    private:
        int* vals;
        int length;
        int front;
        int back;
        int capacity;
    public:
        Queue(int size){
            vals = new(std::nothrow) int[size];
            capacity = size;
            length = 0;
            front = 0;
            back = -1;
        }
        ~Queue(){
            delete vals;
        }
        void enqueue(int value){
            if(isFull()){
                std::cout << "Queue overflow" << std::endl;
                return;
            }
            back = (back +1 ) % capacity;
            vals[back] = value;
            length++;
        }
        void dequeue(){
            if(isEmpty()){
                std::cout << "Queue underflow" << std::endl;
                return;
            }
            front = (front+1)%capacity;
            length--;
        }

        bool isFull(){
            return capacity == length;
        }
        bool isEmpty(){
            return length ==0;
        }
        int size(){
            return length;
        }
        void display(){
            for(int i{front};i<=back;i++){
                std::cout << vals[i] << " -- ";
            }
            std::cout << "NULL"  << std::endl;
        }
};


int main(){
    Queue q1(10);
    q1.enqueue(124);
    q1.enqueue(543);
    q1.enqueue(33);
    q1.display();
    return 0;
}