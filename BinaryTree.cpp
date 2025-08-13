#include<iostream>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int value){
            data = value;
            left = right = nullptr;
        }
};

class BinaryTree{
    private:
        Node* root;
        Node* insert(Node* node, int value){
            if(!node) return new Node(value);
            if(value < node->data) node->left = insert(node->left, value); 
            else node->right = insert(node->right , value);
            return node;
        }
        void preorder(Node* node){
            if(!node)return;
            std::cout << node->data << std::endl;
            preorder(node->left);
            preorder(node->right);
        }
        void inorder(Node* node){
            if(!node) return;
            inorder(node->left);
            std::cout << node->data << std::endl;
            inorder(node->right);
        }
        void postorder(Node* node){
            if(!node) return;
            inorder(node->left);
            inorder(node->right);
            std::cout << node->data << std::endl;
        }
        int height(Node* node){
            if(!node) return 0;
            return 1 + std::max(height(node->left),height(node->right));
        }
        bool search(Node* node , int value){
            if(!node) return false;
            if(node->data == value){
                return true;
            }
            if(value < node->data) return search(node->left, value);
            return search(node->right,value);
        }
        Node* findMin(Node* node){
            while (node&& node->left)
            {
                node = node->left;
            }
            return node;
        }
        Node* remove(Node* node, int value){
            if(!node) return nullptr;
            if(value < node->data) remove(node->left , value);
            else if (value > node->data) remove(node->right , value);
            else {
                if(!node->left){
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                else if(!node->right){
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
                Node* temp = findMin(node->right);
                node->data =temp->data;
                node->right = remove(node->right,temp->data);
            }
            return node;
        }
    public:
    BinaryTree() { root = nullptr; }

    void insert(int value) { root = insert(root, value); }
    void remove(int value) { root = remove(root, value); }
    bool search(int key) { return search(root, key); }
    void inorder() { inorder(root); std::cout << "\n"; }
    void preorder() { preorder(root); std::cout << "\n"; }
    void postorder() { postorder(root); std::cout << "\n"; }
    int height() { return height(root); }
};

int main(){
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder Traversal: ";
    tree.inorder();   // 20 30 40 50 60 70 80

    std::cout << "Preorder Traversal: ";
    tree.preorder();  // 50 30 20 40 70 60 80

    std::cout << "Postorder Traversal: ";
    tree.postorder(); // 20 40 30 60 80 70 50

    std::cout << "Height of Tree: " << tree.height() << "\n"; // 3

    std::cout << "Searching 40: " << (tree.search(40) ? "Found\n" : "Not Found\n");
    std::cout << "Searching 90: " << (tree.search(90) ? "Found\n" : "Not Found\n");

    tree.remove(50);
    std::cout << "After Deleting 50 (Inorder): ";
    tree.inorder(); // 20 30 40 60 70 80
    return 0;
}
