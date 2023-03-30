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
    int count(){
        int count = 0;
        Node *tmp = head;
        while(tmp != NULL){
            count++;
            tmp = tmp->next;
        }
        return count;
    }
    bool isFound(T element){
        Node *ptr = head;
        bool found = false;
        while(ptr != NULL){
            if(element == ptr->data){
                found = true;
                break;
            }
            ptr = ptr->next;
        }
        return found;
    }
    void insertBefore(T Item, T replacer){
        Node *ptr = head;
        while(ptr != NULL){
            if(ptr->next->data == Item){
                Node *newNode = new Node;
                newNode->data = replacer;
                newNode->next = ptr->next;
                ptr->next = newNode;
                break;
            }
            ptr = ptr->next;
        }
    }
    void insertAfter(T item, T replacer){
        Node *ptr = head;
        while(ptr != NULL){
            if(ptr->data == item){
                Node *newNode = new Node;
                newNode->data = replacer;
                newNode->next = ptr->next;
                ptr->next = newNode;
                break;
            }
            ptr = ptr->next;
        }
    }
    void append(T Element){
        Node *ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        Node *newNode = new Node;
        newNode->data = Element;
        newNode->next = NULL;
        ptr->next = newNode;
    }
};
int main(){
    linkedList<int> l1;
    l1.insertFirst(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    l1.append(6);
    l1.insertBefore(6, 5);
    l1.print();
    return 0;
}