#include "./dataStructures.cpp"
#include <iostream>
using namespace std;

void SortQueue(Queue<int> &x){
    int Size = x.queueSize();
    Queue<int> tmp;
    Queue<int> Sorted;
    int min;
    while(!(x.isEmpty())){
        Size = x.queueSize();
        min = x.first();
        for(int i = 0;i<Size;i++){
            if(x.first()<min){
                min = x.first();
            }
            tmp.enqueue(x.dequeue());
        }
        
        for(int i = 0;i<Size;i++){
            if(min == tmp.first()){
                Sorted.enqueue(tmp.dequeue());
                continue;
            }
            x.enqueue(tmp.dequeue());
        }
        
    }
    while(!(Sorted.isEmpty())){
        x.enqueue(Sorted.dequeue());
    }
}

int main(){
    Queue<int> x;
    x.enqueue(1);
    x.enqueue(2);
    x.enqueue(4);
    x.enqueue(6);
    x.enqueue(3);
    x.enqueue(5);
    x.enqueue(1);
    x.enqueue(-1);
    x.enqueue(10);
    x.enqueue(5);
    x.enqueue(6);
    x.enqueue(7);
    x.enqueue(8);
    x.enqueue(9);
    SortQueue(x);
    x.print();

    return 0;
}