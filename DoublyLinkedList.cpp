#include<iostream>

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int value){
            this->data = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList(){
           this->head = nullptr;
           this->tail = nullptr; 
        }
        void insertAtHead(int value){
            Node* newNode = new Node(value);
            if(this->head == nullptr){
                this->head = this->tail = newNode;
                return;
            }
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode; 
            
        }
        void insertAtTail(int value){
            Node* newNode = new Node(value);
            if(this->head == nullptr){
                this->head = this->tail = newNode;
                return ;
            }
            this->tail->next = newNode;
            newNode->prev = tail;
            this->tail = newNode;
        }
        void deleteNode(int value){
            if(this->head == nullptr){
                return;
            }
            if(this->head->data == value){
                Node* temp = this->head;
                head = head->next;
                if(head) this->head->prev = nullptr;
                else this->tail = nullptr;
                delete temp;
                return;
            }
            Node* temp = head;
            while(temp != nullptr && temp->data != value){
                temp = temp->next;
            }
            if(temp == nullptr){
                std::cout << " Data not found " << std::endl;
                return;
            }
            if(temp == this->tail){
                tail = temp->prev;
                tail->next = nullptr;
                delete temp;
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;

        }
        void displayForward(){
            Node* temp = this->head;
            std::cout << "NULL <-> ";
            while(temp != nullptr){
                std::cout << temp->data << " <-> ";
                temp = temp->next;
            }
            std::cout << "NULL\n";
        }
        void displayBackward(){
            Node* temp = this->tail;
            std::cout << "NULL <-> ";
            while(temp != nullptr){
                std::cout << temp->data << " <-> ";
                temp = temp->prev;
            }
            std::cout << "NULL\n";
        }
 };

int main(){
    LinkedList lnklst;
    lnklst.insertAtHead(23543);
    lnklst.insertAtTail(563);
    lnklst.insertAtHead(2345);
    lnklst.insertAtTail(64);
    lnklst.insertAtTail(56);
    lnklst.displayBackward();
    lnklst.displayForward();
    lnklst.deleteNode(64);
    lnklst.displayForward();
    lnklst.displayBackward();
    return 0; 
}