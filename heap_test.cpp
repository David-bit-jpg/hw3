#include "heap.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    Heap<int> intHeap;
    intHeap.push(3);
    intHeap.push(1);
    intHeap.push(4);
    intHeap.push(1);
    intHeap.push(5);
    cout << "intHeap size: " << intHeap.size() << endl;//5
    cout << "intHeap top: " << intHeap.top() << endl;//1
    while(!intHeap.empty())
    {
      cout << intHeap.top() << " ";
      intHeap.pop();
    }
    cout<<endl;
    cout << "pop no problem"<<endl;
    return 0;
}
