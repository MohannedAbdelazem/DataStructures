#include "./dataStructures.cpp"
#include <iostream>
using namespace std;
void DecimalToBinary(int n){
    long long int BinaryNum = 0;
    long long int multiplier = 1;
    while(n != 0){
        BinaryNum += (n%2)*multiplier;
        n = n / 2;
        multiplier*=10;
    }
    cout << BinaryNum << " ";
}
void PrintQueue(Queue<int> x){
    while(!x.isEmpty()){
        DecimalToBinary(x.dequeue());
    }
}
int main(){
    int input;
    cin >> input;
    Queue<int> x;
    for(int i = 1;i<=input;i++){
        x.enqueue(i);
    }
    PrintQueue(x);
    return 0;
}