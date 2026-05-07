#pragma once
#include <cstddef>
#include "link.hpp"

class LinkedListNode {
public:
    Link* data;
    LinkedListNode* next;

    LinkedListNode(Link* data, LinkedListNode* next = nullptr);
    LinkedListNode(const LinkedListNode& lln) = default;
    LinkedListNode& operator=(const LinkedListNode& lln) = default;
    ~LinkedListNode(void) = default;
};

class LinkedList {
private:
    size_t count;
    LinkedListNode* head;

public:
    LinkedList();
    ~LinkedList();

    void insert(Link* link);
    void traverse() const;
};