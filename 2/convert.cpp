#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

int main() {
  string string1 = "Hello";
  cout << "typeID: " << typeid(string1).name();
  string string2 = "Hello";
  if ( typeid(string1).name() == typeid(string2).name() ) {
    cout << "true";
  } else {
    cout << "false";
  }
}
