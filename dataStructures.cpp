#include <iostream>
using namespace std;

template <typename T>
class AMvector
{
private:
    typedef T *iterator;
    iterator iteration;
    int size;
    int capacity;
    T *ptr;

public:
    int GetSize()
    {
        return size;
    }
    int GetCapacity()
    {
        return capacity;
    }
    iterator begin()
    {
        return ptr;
    }
    iterator end()
    {
        return (ptr + size - 2);
    }
    // First constructor
    AMvector(int n = 0)
    {
        size = 0;
        this->capacity = 10;
        if (this->capacity < n)
        {
            capacity = n;
        }
        ptr = new T[capacity];
        iteration = ptr;
    }
    // Second Constructor
    AMvector(T *elements, int n)
    {
        size = n;
        capacity = n;
        ptr = elements;
        ptr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = elements[i];
        }
        iteration = ptr;
    }
    AMvector(AMvector &VectorCpy)
    {
        size = VectorCpy.size;
        capacity = VectorCpy.capacity;
        ptr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            ptr[i] = VectorCpy[i];
        }
    }
    AMvector &operator=(AMvector &VectorCpy)
    {
        size = VectorCpy.size;
        capacity = VectorCpy.capacity;
        ptr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            ptr[i] = VectorCpy[i];
        }
        return *this;
    }
    AMvector &operator=(const AMvector &&VectorCpy)
    {
        size = VectorCpy.GetSize();
        capacity = VectorCpy.GetCapacity();
        for (int i = 0; i < capacity; i++)
        {
            ptr[i] = VectorCpy[i];
        }
    }
    T &operator[](int index)
    {
        try
        {
            if (index >= capacity)
            {
                throw capacity;
            }
            return ptr[index];
        }
        catch (int e)
        {
            cout << e << " Is the max capacity" << endl;
            exit(3);
            return ptr[0];
        }
    }

    int push_back(T element)
    {
        if (size == capacity)
        {
            T *temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = ptr[i];
            }
            delete[] ptr;
            capacity *= 2;
            ptr = temp;
            iteration = ptr;
        }
        ptr[size] = element;
        size++;
        return size;
    }
    T pop_back()
    {
        size--;
        return ptr[size];
    }
    void erase(T element)
    {
        size--;
        T *temp = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            if (&(ptr[i]) != NULL)
            {
                temp[i] = ptr[i];
            }
        }
        delete[] ptr;
        ptr = temp;
        iteration = ptr;
    }
    // deletes from the element after start to the element after the ending
    void erase(T start, T ending)
    {
        while (start != ending + 1)
        {
            erase(start);
            start++;
        }
    }
    void clear()
    {
        size = 0;
        // for (int i = 0; i < capacity; i++)
        // {
        //     &(ptr[i]) = NULL;
        // }
    }
    bool operator==(const AMvector<T> &other)
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] != other.ptr[i])
                return false;
        }
        return true;
    }
    bool operator<(const AMvector<T> &other)
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] >= other.ptr[i])
                return false;
        }
        return true;
    }
    void resize(int NewCapacity)
    {
        // Check it out later or after abdo checks it out
        T *temp = new T[NewCapacity];
        for (int i = 0; i < capacity; i++)
        {
            if (&(ptr[i]) != NULL)
            {
                temp[i] = ptr[i];
            }
        }
        capacity = NewCapacity;
        delete[] ptr;
        ptr = temp;
        iteration = ptr;
        if (capacity < size)
        {
            size = capacity;
        }
    }
    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, AMvector<T> &vec)
    {
        for (int i = 0; i < vec.GetSize(); i++)
        {
            out << vec[i] << " ";
        }
        out << endl;
        return out;
    }
    void operator++()
    {
        iteration++;
    }

    T operator*()
    {
        return *iteration;
    }
    void operator+(int index)
    {
        iteration += index;
    }
};


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