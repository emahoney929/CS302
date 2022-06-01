/** Link-based Implementation file of the ADT binary search tree.
    @file BinarySearchTree.cpp */
#include "BinarySearchTree/BinarySearchTree.h"
#include <iostream>
#include <memory>

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
    : rootPtr(nullptr) {}  // end of Default Constructor

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType &rootItem)
    : rootPtr(std::make_shared<BinaryNode<ItemType>>(
          rootItem, nullptr, nullptr)) {}  // end of Parameterized Constructor

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(
    const BinarySearchTree<ItemType> &tree) {}  // end of Copy Constructor

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
  clear();  // Deletes all the data in the tree.
}

template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const  // Checks for Empty Tree
{
  if (rootPtr) {
    return false;
  }

  return true;  // States Tree is empty
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
  if (!isEmpty()) {
    return this->getHeightHelper(
        rootPtr);  // Utilizes the helper function to get the height
  }

  return 0;  // Returns zero if the list is empty
}

//Function to return the number of nodes in the BST.
template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
  if (!isEmpty()) {
    int count = 0;
    return this->getNumberOfNodesHelper(count, rootPtr);	//Calls on helper function
  }

  return 0;
}

//Returns the internal data from the node
template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const {
  return rootPtr->getItem();	//Uses Node function to return item
}

//Adds
template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &anEntry) {
  auto newPtr = std::make_shared<BinaryNode<ItemType>>(anEntry);
  rootPtr = placeNode(rootPtr, newPtr);	//Uses helper function to place new node in correct position
  return true;
}

//Clears every node in the BST
template <class ItemType>
void BinarySearchTree<ItemType>::clear() {
  this->destroyTree(rootPtr);
  rootPtr = nullptr;
}

//Traverses the tree in preorder fashion
template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const {
  if (!isEmpty()) {
    this->preorder(rootPtr);
  }
}

//Traverses the tree in inorder fashion
template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const {
  if (!isEmpty()) {
    this->inorder(rootPtr);
  }
}

//Traverses the tree in postorder fashion
template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const {
  if (!isEmpty()) {
    this->postorder(rootPtr);
  }
}

//Helper function to place node in BST
template <class ItemType>
auto BinarySearchTree<ItemType>::placeNode(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
    std::shared_ptr<BinaryNode<ItemType>> newNode) {
  if (!subTreePtr) {
    return newNode;
  } else {
    if (subTreePtr->getItem() < newNode->getItem()) {
      auto rightPtr = subTreePtr->getRightChildPtr();
      rightPtr = placeNode(rightPtr, newNode);
      subTreePtr->setRightChildPtr(rightPtr);
    } else {
      auto leftPtr = subTreePtr->getLeftChildPtr();
      leftPtr = placeNode(leftPtr, newNode);
      subTreePtr->setLeftChildPtr(leftPtr);
    }
  }

  return subTreePtr;
}
