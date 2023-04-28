#include "dataStructures.cpp"
#include <stdarg.h>
#include <iostream>
#include <vector>
using namespace std;

linkedList<int> merge(vector<linkedList<int>> lists){
    linkedList<int> solution;
    for(auto list: lists){
        if(solution.isEmpty()){
            for(int i = 0;i<list.count();i++){
                solution.insertAtTail(list.retreiveAt(i));
            }
        }
        else{
            //merge ba2a
            for(int i = 0;i<list.count();i++){
                for(int j = 0;j<solution.count();j++){
                    if(list.retreiveAt(i)<=solution.retreiveAt(j)){
                        solution.insertAt(j ,list.retreiveAt(i));
                        break;
                    }
                    else if(j == solution.count()-1){
                        solution.insertAt(j+1 ,list.retreiveAt(i));
                        break;
                    }
                }
            }
        }
    }
    return solution;
}

int main(){
    linkedList<int> x;
    x.insertAtTail(4);
    x.insertAtTail(3);
    x.insertAtTail(2);
    x.insertAtTail(1);
    x.insertAtTail(0);
    linkedList<int> y;
    y.insertAtHead(4);
    y.insertAtHead(3);
    y.insertAtHead(2);
    y.insertAtHead(1);
    y.insertAtHead(0);
    linkedList<int> z;
    z.insertAtHead(-1);
    z.insertAtTail(3);
    z.insertAtTail(5);
    z.insertAtHead(99);
    z.insertAtHead(-5);
    z.insertAtHead(3);
    vector<linkedList<int>> lists;
    lists.push_back(y);
    lists.push_back(x);
    lists.push_back(z);
    linkedList<int> merged = merge(lists);
    merged.print();
}