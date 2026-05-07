#include "hello.hpp"
#include <iostream>
using namespace std;

LinkedListNode::LinkedListNode(Link* data, LinkedListNode* next)
{
   this->data = data;
   this->next = next;
}

LinkedList::LinkedList()
{
   count = 0;
   head = nullptr;
}

LinkedList::~LinkedList()
{
   LinkedListNode* curr_node = head;
   while (curr_node != nullptr) {
      LinkedListNode* next = curr_node->next;
      delete curr_node->data;
      delete curr_node;
      curr_node = next;
   }
}

void LinkedList::insert(Link* link)
{
   LinkedListNode* new_ptr = new LinkedListNode(link, head);
   head = new_ptr;
   ++count;
}

void LinkedList::traverse() const
{
   LinkedListNode* curr_node = head;
   while (curr_node != nullptr) {
      cout << curr_node->data->get_material() << ' ';
      curr_node = curr_node->next;
   }
   cout << '\n';
}