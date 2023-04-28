#include "dataStructures.cpp"

linkedList<int> CombineNodes(linkedList<int> list)
{
    int sum = 0, i = 1;
    int size = list.count();
    linkedList<int> result;

    while (i < size)
    {
        if (list.retreiveAt(i))
        {
            sum += list.retreiveAt(i);
        }
        else
        {
            result.insertAtTail(sum);
            sum = 0;
        }
        i++;
    }

    return result;


int main()
{
    linkedList<int> list, result;
    list.insertAtTail(0);
    list.insertAtTail(3);
    list.insertAtTail(1);
    list.insertAtTail(0);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(2);
    list.insertAtTail(0);

    result = CombineNodes(list);
    result.print();
}
