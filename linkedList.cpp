#include <iostream>
using namespace std;

template <typename T>
class linkedList{
    private:
    class Node{
        public:
        T data;
        Node *next;
    };
    public:
    Node *head;
    linkedList(){
        head = NULL;
    }
    void insertFirst(T element){
        Node *newNode = new Node;
        newNode->data = element;
        if(head == NULL){
            head = newNode;
            newNode->next = NULL;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    void print(){
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data;
            ptr = ptr->next;
        }
        
    }
};
int main(){
    linkedList<int> l1;
    l1.insertFirst(1);
    l1.insertFirst(2);
    l1.insertFirst(3);
    l1.insertFirst(4);
    l1.print();
    return 0;
}