#include <iostream>
#include "src/hello.hpp"
using namespace std;

int main() {
  LinkedList list;

  list.insert(new Link("Steel"));
  list.insert(new Link("Iron"));
  list.insert(new Link("Copper"));

  cout << "Traversing from HEAD:" << endl;
  list.traverse();

  return 0;
}