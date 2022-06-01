//--------------------------------------------------------------------
//
//  StackLinked.cpp
//
//  Class implementation for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#include "StackLinked/StackLinked.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
    : top(nullptr) {}  // Initializes an empty stack with top as a nullptr.

// Copy Ctor to copy contents of right-hand side to newly initialized stack.
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other) {
  if (!other.isEmpty()) {  // Check for empty Stack else
    StackNode* current = other->top;

    while (current !=
           nullptr) {  // Reuses the push function to push data onto new stack
      push(current->dataItem);
      current = current->next;
    }
  } else {
    top = nullptr;
  }
}

// Operator overload to assign the data from one stack to another.
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(
    const StackLinked& other) {
  if (this != &other) {  // Check for self assignment
    if (!other.isEmpty()) {
      StackNode* current = other->top;

      while (current != nullptr) {
        push(current->dataItem);
        current = current->next;
      }
    } else {
      top = nullptr;  // On failed attempt to assign data set the top equal to
                      // nullptr
    }
  }

  return *(this);
}

// Dtor
template <typename DataType>
StackLinked<DataType>::~StackLinked() {
  if (!isEmpty()) {
    StackNode* curr = top;

    while (curr != nullptr) {
      StackNode* del_Node = curr;
      curr = curr->next;
      del_Node->next = nullptr;
      delete del_Node;
    }
  }
}

// Function to append data to the top of the stack.
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw(
    logic_error) {
  if (isEmpty()) {  // Check in case stack is empty initially
    StackNode* newNode = new StackNode(newDataItem, top);
    top = newNode;
    top->next = nullptr;
  } else {
    StackNode* newNode = new StackNode(newDataItem, top);
    top = newNode;
  }
}

// Function to remove data from the top of the stack.
template <typename DataType>
DataType StackLinked<DataType>::pop() throw(logic_error) {
  if (!isEmpty()) {  // Check to make sure the stack is not empty beforehand
    StackNode* Del_Node = top;
    DataType itemToDelete = top->dataItem;
    top = top->next;
    Del_Node->next = nullptr;
    delete Del_Node;
    return itemToDelete;
  } else {
    throw(logic_error("Stack is Empty\n"));  // Throws a logic error in case the
                                             // stack is empty
  }
}

// Function to remove all the data from the stack.
template <typename DataType>
void StackLinked<DataType>::clear() {
  if (!isEmpty()) {
    StackNode* curr = top;
    StackNode* node_to_delete;

    while (curr != nullptr) {  // Iterate through stack deleting each element
                               // and freeing allocated memory
      node_to_delete = curr;
      curr = curr->next;
      node_to_delete->next = nullptr;
      delete node_to_delete;
    }
    top = nullptr;
  }
}

// Function to check ig the stack is empty.
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const {
  return top == nullptr;
}

// Function to check if the stack is full.
template <typename DataType>
bool StackLinked<DataType>::isFull() const {
  return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
  if (isEmpty()) {
    cout << "Empty stack" << endl;
  } else {
    cout << "Top\t";
    for (StackNode* temp = top; temp != 0; temp = temp->next) {
      if (temp == top) {
        cout << "[" << temp->dataItem << "]\t";
      } else {
        cout << temp->dataItem << "\t";
      }
    }
    cout << "Bottom" << endl;
  }
}

template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData,
                                            StackNode* nextPtr) {
  dataItem = nodeData;
  next = nextPtr;
}
