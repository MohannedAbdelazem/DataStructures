#include "./dataStructures.cpp"
#include <iostream>
using namespace std;
class StackUsingQueue{
private:
Queue<int> main;
Queue<int> sub;
public:
void push(int data){
    if(main.isEmpty()){
        main.enqueue(data);
    }
    else{
        while(!(main.isEmpty())){
            sub.enqueue(main.dequeue());
        }
        main.enqueue(data);
        while(!(sub.isEmpty())){
            main.enqueue(sub.dequeue());
        }
    }
}
int pop(){
    int data = main.dequeue();
    return data;
}
void Print(){
    main.print();
}
};

int main(){
    StackUsingQueue x;
    x.push(1);
    x.push(2);
    x.push(3);
    x.push(4);
    x.Print();
    cout << x.pop() << endl;
    cout << x.pop() << endl;
    cout << endl << endl;
    x.Print();

}