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
    virtual void insertAtHead(T element){
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
        if(ptr == NULL){
            cout << "The linked list is empty" << endl;
        }
        else{
            while (ptr != NULL)
            {
                cout << ptr->data << endl;
                ptr = ptr->next;
            }  
        
        }
    }
    bool isEmpty(){
        return (head == NULL);
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
    bool isExist(T element){
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
    // void insertBefore(T Item, T replacer){
    //     Node *ptr = head;
    //     while(ptr != NULL){
    //         if(ptr->next->data == Item){
    //             Node *newNode = new Node;
    //             newNode->data = replacer;
    //             newNode->next = ptr->next;
    //             ptr->next = newNode;
    //             break;
    //         }
    //         ptr = ptr->next;
    //     }
    // }
    
    void insertAtTail(T element){
        Node *node = new Node;
        node->data = element;
        node->next = NULL;
        if(isEmpty()){
            head = node;
        }
        else{
            Node *ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = node;
        }
    }
    void clear(){
        head = NULL;
    }
    void removeAtHead(){
        if(isEmpty()){
            cout << "The list is already empty" << endl;
        }
        else{
            Node *ptr = head;
            head = head->next;
            delete ptr;
        }
    }
    void removeAtTail(){
        if(isEmpty()){
            cout << "The list is already empty" << endl;
        }
        else{
            Node *ptr = head;
            while(ptr->next->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = NULL;
        }
    }
    void insertAt(int index, T element){
        // Node *node = new Node;
        // node->data = element;
        Node *ptr = head;
        if(index == 0){
            insertAtHead(element);
        }
        else if(index> (count())){
            cout << "Out of range" << endl;
        }
        else if(index == (count())){
            insertAtTail(element);
        }
        else{
            for(int i = 0;i<index-1;i++){
               ptr = ptr->next;
            }
            Node *node = new Node;
            node->data = element;
            node->next = ptr->next;
            ptr->next = node;
        }
    }
    T retreiveAt(int index){
        //The first element will be returned by default if the element was not found
        T result = head->data;
        if(index > (count()-1)){
            cout << "Out of range.... returning head element by default" << endl;
        }
        else{
            Node *ptr = head;
            for(int i = 0;i<index;i++){
                ptr = ptr->next;
            }
            result = ptr->data;
        }
        return result;
    }
    void replaceAt(T replacer, int index){
        if(index > (count()-1)){
            cout << "Out of range" << endl;
        }
        else{
            Node *ptr = head;
            for(int i = 0;i<index;i++){
                ptr = ptr->next;
            }
            ptr->data = replacer;
        }
    }
    bool isItemAtEqual(T element, int index){
        return (retreiveAt(index) == element);
    }
    void swap(int FirstIndex, int SecondIndex){
        if(FirstIndex > (count()-1)|| SecondIndex > (count()-1)){
            cout << "Can't swap..... elements are out of range" << endl;
        }
        else{
            Node *ptr1 = head;
            for(int i = 0;i<FirstIndex;i++){
                ptr1 = ptr1->next;
            }
            Node *ptr2 = head;
            for(int i = 0;i<SecondIndex;i++){
                ptr2 = ptr2->next;
            }
            Node *tmpPtr = ptr1;
            ptr1 = ptr2;
            ptr2 = tmpPtr;
        }
    }
    void removeAt (int index){
        if(isEmpty()){
            cout << "Can't remove ..... Linked list is empty" << endl;
        }
        else if(index >= count()){
            cout << "Can't remove ..... index is out of range" << endl;
        }
        else if(index == 0){
            removeAtHead();
        }
        else if(index == (count()-1)){
            removeAtTail();
        }
        else{
            Node *ptr = head;
            for(int i = 0;i<index-1;i++){
                ptr = ptr->next;
            }
            Node *deleted = ptr->next;
            ptr->next = deleted->next;
            delete deleted;
        }
    }
};

//Double linked list
template <typename T>
class DoubleLinkedList{
    private:
    struct Node{
        T data;
        Node *previous;
        Node *Next;
    };
    public:
    Node *head;
    Node *tail;
    DoubleLinkedList(){
        head = NULL;
        tail = NULL;
    }
    int count(){
        int count = 0;
        Node *tmp = head;
        while(tmp != NULL){
            count++;
            tmp = tmp->Next;
        }
        return count;
    }
    bool isEmpty(){
        return (head == NULL);
    }
    void insertAtHead(T element){
        Node *node = new Node;
        node->data = element;
        node->previous = NULL;
        if(isEmpty()){
            node->Next = NULL;
            head = node;
            tail = node;
        }
        else{
            node->Next = head;
            head->previous = node;
            head = node;
        }
    }
    void forwardTraversal(){
        Node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << endl;
            ptr = ptr->Next;
        }
    }
    void backwardTraversal(){
        Node *ptr = tail;
        while(ptr != NULL){
            cout << ptr->data << endl;
            ptr = ptr->previous;
        }

    }
    void insertAtTail(T element){
        Node *node = new Node;
        node->data = element;
        node->Next = NULL;
        if(isEmpty()){
            head = node;
            node->previous = NULL;
        }
        else{
            Node *ptr = head;
            while(ptr->Next != NULL){
                ptr = ptr->Next;
            }
            ptr->Next = node;
            node->previous = ptr;
        }
        tail = node;
    }
    void insertAt(int index, T element){
        // Node *node = new Node;
        // node->data = element;
        Node *ptr = head;
        if(index == 0){
            insertAtHead(element);
        }
        else if(index> (count())){
            cout << "Out of range" << endl;
        }
        else if(index == (count())){
            insertAtTail(element);
        }
        else{
            for(int i = 0;i<index-1;i++){
               ptr = ptr->Next;
            }
            Node *node = new Node;
            node->data = element;
            node->Next = ptr->Next;
            Node *prev = ptr->Next;
            prev->previous = node;
            ptr->Next = node;
            node->previous = ptr;
        }
    }
    void clear(){
        head = NULL;
        tail = NULL;
    }
    int doubleLinkedListSize(){
        return count();
    }
    T retreiveAt(int index){
        //The first element will be returned by default if the element was not found
        T result = head->data;
        if(index > (count()-1)){
            cout << "Out of range.... returning head element by default" << endl;
        }
        else{
            Node *ptr = head;
            for(int i = 0;i<index;i++){
                ptr = ptr->Next;
            }
            result = ptr->data;
        }
        return result;
    }
    bool isItemAtEqual(T element, int index){
        return (retreiveAt(index) == element);
    }
    void replaceAt(T replacer, int index){
        if(index > (count()-1)){
            cout << "Out of range" << endl;
        }
        else{
            Node *ptr = head;
            for(int i = 0;i<index;i++){
                ptr = ptr->Next;
            }
            ptr->data = replacer;
        }
    }
    bool isExist(T element){
        Node *ptr = head;
        bool found = false;
        while(ptr != NULL){
            if(element == ptr->data){
                found = true;
                break;
            }
            ptr = ptr->Next;
        }
        return found;
    }
    void swap(int FirstIndex, int SecondIndex){
        if(FirstIndex > (count()-1)|| SecondIndex > (count()-1)){
            cout << "Can't swap..... elements are out of range" << endl;
        }
        else{
            Node *ptr1 = head;
            for(int i = 0;i<FirstIndex;i++){
                ptr1 = ptr1->Next;
            }
            Node *ptr2 = head;
            for(int i = 0;i<SecondIndex;i++){
                ptr2 = ptr2->Next;
            }
            Node *tmpPtr = ptr1;
            ptr1 = ptr2;
            ptr2 = tmpPtr;
        }
    }
    void removeAtHead(){
        if(isEmpty()){
            cout << "The list is already empty" << endl;
        }
        else{
            Node *ptr = head;
            head = head->Next;
            head->previous = NULL;
            delete ptr;
        }
    }
    void removeAtTail(){
        if(isEmpty()){
            cout << "The list is already empty" << endl;
        }
        else{
            tail = tail->previous;
            tail->Next = NULL;
        }
    }

    void removeAt (int index){
        if(isEmpty()){
            cout << "Can't remove ..... Linked list is empty" << endl;
        }
        else if(index >= count()){
            cout << "Can't remove ..... index is out of range" << endl;
        }
        else if(index == 0){
            removeAtHead();
        }
        else if(index == (count()-1)){
            removeAtTail();
        }
        else{
            Node *ptr = head;
            for(int i = 0;i<index-1;i++){
                ptr = ptr->Next;
            }
            Node *deleted = ptr->Next;
            Node *nptr = deleted->Next;
            ptr->Next = nptr;
            nptr->previous = ptr;
            delete deleted;
        }
    }
};

template <typename T>
class CircularLinkedList{
    private:
    int length;
    struct Node{
        T data;
        Node *Next;
    };
    public:
    Node *head;
    Node *tail;
    CircularLinkedList():length(0)
    {
        head = tail = NULL;
    }
    bool isEmpty(){
        return (length == 0);
    }
    void insertAtHead(T element){
        Node *node = new Node;
        node->data = element;
        if(isEmpty()){
            head = tail = node;
            head->Next = tail;
            tail->Next = head;
        }
        else{
            node->Next = tail->Next;
            tail->Next = node;
            head = node;
        }
        length++;
    }
    void insertAtEnd(T element){
        if(isEmpty()){
            insertAtHead(element);
            return;
        }
        else{
            Node *node = new Node;
            node->data = element;
            node->Next = tail->Next;
            tail->Next = node;
            tail = node;
        }
        length++;
    }
    void print(){
        if(length == 0){
            cout << "Can't print .... list is empty" << endl;

        }
        else{
            Node *ptr = head;
            int i = 0;
            while(i++ != length){
                cout << ptr->data << endl;
                ptr = ptr->Next;
            }
        }
    }
    void insertAt(int index, T element){
        // Node *node = new Node;
        // node->data = element;
        Node *ptr = head;
        if(index == 0){
            insertAtHead(element);
            return;
        }
        else if(index> (length)){
            cout << "Out of range" << endl;
            return;
        }
        else if(index == (length)){
            insertAtEnd(element);
            return;
        }
        else{
            for(int i = 0;i<index-1;i++){
               ptr = ptr->Next;
            }
            Node *node = new Node;
            node->data = element;
            node->Next = ptr->Next;
            ptr->Next = node;
        }
        length++;
    }
    void removeAtHead(){
        if(isEmpty()){
            cout << "Can't remove items....... List already empty" << endl;
        }
        else{
            Node *deleted = head;
            tail->Next = deleted->Next;
            head = tail->Next;
            delete deleted;
            length--;
        }
    }
    void removeAtEnd(){
        if(isEmpty()){
            cout << "Can't remove items....... List already empty" << endl;
        }
        else{
            Node *ptr = head;
            while(ptr->Next != tail){
                ptr = ptr->Next;
            }
            Node *deleted = tail;
            ptr->Next = tail->Next;
            tail = ptr;
            delete deleted;
            length--;
        }
    }
    void removeAt (int index){
        if(isEmpty()){
            cout << "Can't remove ..... Linked list is empty" << endl;
        }
        else if(index >= length){
            cout << "Can't remove ..... index is out of range" << endl;
        }
        else if(index == 0){
            removeAtHead();
        }
        else if(index == (length - 1)){
            removeAtEnd();
        }
        else{
            Node *ptr = head;
            for(int i = 0;i<index-1;i++){
                ptr = ptr->Next;
            }
            Node *deleted = ptr->Next;
            ptr->Next = deleted->Next;
            delete deleted;
            length--;
        }
    }
    int circularLinkedListSize(){
        return length;
    }
    T retreiveAt(int index){
        //The first element will be returned by default if the element was not found
        T result = head->data;
        if(index > (length-1)){
            cout << "Out of range.... returning head element by default" << endl;
        }
        else{
            Node *ptr = head;
            for(int i = 0;i<index;i++){
                ptr = ptr->Next;
            }
            result = ptr->data;
        }
        return result;
    }
    void replaceAt(T replacer, int index){
        if(index > (length - 1)){
            cout << "Out of range" << endl;
        }
        else{
            Node *ptr = head;
            for(int i = 0;i<index;i++){
                ptr = ptr->Next;
            }
            ptr->data = replacer;
        }
    }
    bool isExist(T element){
        Node *ptr = head;
        bool found = false;
        int i = 0;
        while(i++ != (length)){
            if(element == ptr->data){
                found = true;
                break;
            }
            ptr = ptr->Next;
        }
        return found;
    }
    bool isItemAtEqual(T element, int index){
        return (retreiveAt(index) == element);
    }
    void swap(int FirstIndex, int SecondIndex){
        if(FirstIndex > (length-1)|| SecondIndex > (length-1)){
            cout << "Can't swap..... elements are out of range" << endl;
        }
        else{
            Node *ptr1 = head;
            for(int i = 0;i<FirstIndex;i++){
                ptr1 = ptr1->Next;
            }
            Node *ptr2 = head;
            for(int i = 0;i<SecondIndex;i++){
                ptr2 = ptr2->Next;
            }
            Node *tmpPtr = ptr1;
            ptr1 = ptr2;
            ptr2 = tmpPtr;
        }
    }
    void clear(){
        head = NULL;
        tail = NULL;
        length = 0;
    }

};

int main(){
    CircularLinkedList<int> x;
    x.insertAt(0, 0);
    x.insertAt(1, 1);
    x.insertAt(2, 2);
    x.insertAt(3, 4);
    x.insertAt(3, 3);
    x.insertAt(5, 6);
    x.replaceAt(5, 5);
    x.insertAt(6, 36);
    x.print();

    return 0;
} 