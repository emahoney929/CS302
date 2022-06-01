/** Implementation file for Binary Node
    @file BinaryNode.cpp */

#include "BinaryNode/BinaryNode.h"
#include <memory>

template <class ItemType>
BinaryNode<ItemType>::BinaryNode()
    : leftChildPtr(nullptr), rightChildPtr(nullptr) {}	//end of Default Constructor

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
    : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr) {}	//end of Parameterized Constructor

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(
    const ItemType& anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr,
    std::shared_ptr<BinaryNode<ItemType>> rightPtr) {
  item = anItem;
  leftChildPtr = leftPtr;
  rightChildPtr = rightPtr;
}	//end of Parameterized Constructor

//Setter to set item of root pointer
template <class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
  item = anItem;
}

//Getter to return item from root pointer
template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
  return item;
}

//Checks to see if Node is a leaf
template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
  if (leftChildPtr && rightChildPtr) {
    return false;
  }

  return true;
}

//Returns left Child Pointer
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeftChildPtr() const {
  return leftChildPtr;
}

//Returns right Child Pointer
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getRightChildPtr() const {
  return rightChildPtr;
}

//Returns left Child Pointer
template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(
    std::shared_ptr<BinaryNode<ItemType>> leftPtr) {
  leftChildPtr = leftPtr;
}

//Returns right Child Pointer
template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(
    std::shared_ptr<BinaryNode<ItemType>> rightPtr) {
  rightChildPtr = rightPtr;
}
