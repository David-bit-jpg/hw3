#include "stack.h"
#include <iostream>
#include <fstream>
#include <functional>
using namespace std;
int main()
{
  Stack<int> myStack;
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  cout<<"HERE"<<endl;
  cout<<myStack.size()<<endl; //3
  cout << myStack.top() << endl;  //3
  myStack.pop();
  cout << myStack.top() << endl;  //2
  return 0;
}
