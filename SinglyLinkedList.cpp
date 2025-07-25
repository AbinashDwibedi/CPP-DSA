#include<iostream>

class Node{
    public:
        int data;
        Node* next;
        Node(int value){
            this->data = value;
            this->next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            this->head = nullptr;
        }
        void insertAtEnd(int value){
            Node* newNode = new Node(value);
            if(this->head == nullptr){
                this->head = newNode;
                return;
            }
            Node* temp = this->head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        void insertAtStart(int value){
            Node* newNode = new Node(value);
            newNode->next = this->head;
            this->head = newNode;
        }
        void deleteNode(int value){
            if(head == nullptr) return;
            if(this->head->data == value){
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            Node* temp = head;
            while(temp->next != nullptr && temp->next->data != value){
                temp = temp->next;
            }
            if(temp->next == nullptr){
                std::cout << "No value found to delete" << std::endl;
            }
             Node* toDelete = temp->next;
             temp->next = temp->next->next;
             delete toDelete;
        }
        bool search(int value){
            Node* temp = this->head;
            while(temp!=nullptr){
                if(temp->data == value){
                    return true;
                }
                temp = temp->next;            }
            return false;
        }
        void display(){
            Node* temp = this->head;
            while(temp != nullptr){
                std::cout << " " << temp->data << " ";
                if(temp->next!=nullptr){
                   std::cout << "->" ; 
                }
                temp = temp->next;
            }
            std::cout << "\n";
        }
};

int main(){
    LinkedList lnlst;
    lnlst.insertAtStart(1234);
    lnlst.insertAtEnd(2353);
    lnlst.display();
    lnlst.insertAtEnd(343);
    lnlst.display();
    lnlst.deleteNode(2353);
    lnlst.display();
    return 0;
}