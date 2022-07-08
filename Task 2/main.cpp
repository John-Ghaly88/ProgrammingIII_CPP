
// make sure you include your own header file with the righ name .
// make sure you implement the methods using the same signature as the assignment

#include <iostream>
#include "dlist.h"
#include "dlist.cpp"

using namespace std;

int main(int argc, char* argv[])
{
  DList queue;

  initializeDList(queue);

  //insert 5 values
  for (int i = 1; i <= 5; i++) {
    cout << "put: " << 10 * i << endl;
    put(queue, 10 * i);
  }
    cout<<"______________________________________________________________________________"<<endl;
  //remove 3 values and print them to console
  for (int j = 1; j <= 3; j++) {
    int value;
    if (get(queue, value))
       cout << "     get: " << value << endl;
  }
  cout<<""<<endl;
  cout << "Length: " << dlistLength(queue) << endl;
  cout<<"______________________________________________________________________________"<<endl;


  //insert 5 values
  for (int i = 6; i <= 10; i++) {
    cout << "put: " << 10 * i << endl;
    put(queue, 10 * i);
  }
  cout<<""<<endl;
  cout << "Length: " << dlistLength(queue) << endl;
  cout<<"______________________________________________________________________________"<<endl;


  //remove all values and print them
  while(!isEmpty(queue)) {
    int value;
    get(queue, value);
    cout << "     get: " << value << endl;
  }
cout<<"______________________________________________________________________________"<<endl;
  cin.sync(); cin.get();
  return 0;
}
