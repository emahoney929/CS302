//--------------------------------------------------------------------
//
//  StackArray.cpp
//
//  Class implementation for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#include "StackArray.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber) : top(-1) {
  dataItems = new DataType[Stack<DataType>::MAX_STACK_SIZE];
  maxSize = Stack<DataType>::MAX_STACK_SIZE;
}  // End of Default Constructor

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray<DataType>& other) {
  if (!other.isEmpty()) {
    dataItems = new DataType[other.maxSize];
    maxSize = other.maxSize;

    for (int i = 0; i < other.maxSize; i++)  // Assigns Data to Stack
    {
      dataItems[i] = other.dataItems[i];
    }

    top = maxSize--;
  } else {
    // throw(logic_error);
    dataItems = nullptr;
    top = -1;
  }
}  // End of Parameterized Constructor

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(
    const StackArray<DataType>& other) {
  if (this != &other)  // Check for self-assignment
  {
    if (!other.isEmpty()) {
      delete[] dataItems;  // Erases prior memory in Stack
      dataItems = new DataType[other.maxSize];
      maxSize = other.maxSize;

      for (int i = 0; i < other.maxSize; i++) {
        dataItems[i] = other.dataItems[i];
      }

      top = other.top;
    } else {
      // throw(logic_error);
      dataItems = nullptr;  // Creates an empty Stack
      top = -1;
    }
  }

  return *this;
}  // End of Copy Constructor

template <typename DataType>
StackArray<DataType>::~StackArray() {
  delete[] dataItems;
  dataItems = nullptr;
  top = -1;
}  // End of Destructor

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw(
    logic_error) {
  if (!isFull())  // Check for full Stack
  {
    top++;
    dataItems[top] = newDataItem;
  } else {
    throw(logic_error("Stack is full\n"));
  }
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw(logic_error) {
  if (!isEmpty()) {
    top--;
    return dataItems[top + 1];
  } else {
    throw(logic_error("Stack is Empty\n"));
  }
}

template <typename DataType>
void StackArray<DataType>::clear() {
  top = -1;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const {
  if (top < 0) {
    return true;
  }

  return false;
}

template <typename DataType>
bool StackArray<DataType>::isFull() const {
  return top == (maxSize - 1);
}

template <typename DataType>
void StackArray<DataType>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
  if (isEmpty()) {
    cout << "Empty stack." << endl;
  } else {
    int j;
    cout << "Top = " << top << endl;
    for (j = 0; j < maxSize; j++) cout << j << "\t";
    cout << endl;
    for (j = 0; j <= top; j++) {
      if (j == top) {
        cout << '[' << dataItems[j] << ']' << "\t";  // Identify top
      } else {
        cout << dataItems[j] << "\t";
      }
    }
    cout << endl;
  }
  cout << endl;
}