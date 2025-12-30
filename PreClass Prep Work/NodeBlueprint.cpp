#include <iostream>
#include <string>


template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T value){
        data = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
    Node<T>* head;

    public:
    LinkedList() {
        head = nullptr;
    }

    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if(head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;

            while(temp->next != nullptr) {
                temp = temp -> next; 
            }

            temp -> next = newNode;
            // head = newNode;

        }
    }
    void display() {
        Node<T>* temp = head;
        while(temp != nullptr){
            std::cout << temp -> data << std::endl;
            temp = temp -> next;
        }
    }
    ~LinkedList(){
        Node<T>* current = head;
        while(current != nullptr) {
            Node<T>* temp = current;
            current = temp -> next;
            delete temp;
        }        
    }

};


int main(){
    LinkedList<int>* list = new LinkedList<int>();

    list->append(10);
    list->append(100);
    list->append(1000);
    list->append(10000);

    list->display();

    delete list;
    return 0;
}