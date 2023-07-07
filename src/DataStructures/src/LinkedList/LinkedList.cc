#include "LinkedList.hpp"
#include <array>
#include <cstdlib>
#include <iostream>
template class LinkedListNode<double>;

int main() {

  LinkedListNode<double> node1(1);
  LinkedListNode<double> node2(2);
  LinkedListNode<double> node3(3);
  node1.setNext(node2);
  node2.setNext(node3);

  node1.printForwardChilds();
  node3.printBackwardChilds();
}