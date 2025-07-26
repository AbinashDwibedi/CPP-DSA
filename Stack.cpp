#include<iostream>

class Stack{
    private:
        int* data;
        int top;
        int capacity;
    public:
        Stack(int size){
            data = new(std::nothrow) int[size];
            capacity = size;
            top = -1;

        }
        ~Stack(){
            delete[] data;
        }
        bool isFull(){
            return capacity == top+1; 
        }
        bool isEmpty(){
            return (top+1) == 0;
        }
        void push(int value){
            if(isFull()){
                std::cout << "Stack Overflow" << std::endl;
                return;
            }
            data[++top] = value;
        }
        void pop(){
            if(isEmpty()){
                std::cout << "Stack is already empty" << std::endl;
                return;
            }
            --top;
        }
        void display(){
            if(!isEmpty()){
                for(int i{top};i>=0;i--){
                    std::cout << data[i] << "\n" 
                    "------------" << std::endl; 
                }
            }
        }
        int length(){
            return top+1;
        }
};
int main(){
    Stack stack(10);
    stack.push(523);
    stack.push(53);
    stack.push(5323);
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}