/** Link-based implementation file of the Binary Tree Structure.
    @file BinaryNodeTree.cpp */

#include "BinaryNodeTree/BinaryNodeTree.h"
#include <algorithm>
#include <iostream>
#include <memory>

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr) {}   //end of Default Constructor

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
    : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem)) {}  //end of Parameterized Constructor

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(
    const ItemType& rootItem,
    const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
    const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
    : rootPtr(std::make_shared<BinaryNode<ItemType>>(
          rootItem, copyTree(leftTreePtr->rootPtr),
          copyTree(rightTreePtr->rootPtr))) {}		//end of Parameterized Constructor

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree) {
  rootPtr = copyTree(tree.rootPtr);
}	//end of Copy Constructor

template <class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree() {
  clear();
}	//end of Destructor

//Function check for and empty Binary Tree
template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {
  if (rootPtr) {
    return false;
  }

  return true;
}

//Returns the height of a Binary Tree
template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {
  return getHeightHelper(rootPtr);	//Uses helper function to find height
}

//Returns the number of nodes in a Binary Tree
template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {
  int count = 0;
  return getNumberOfNodesHelper(count, rootPtr);	//Uses a helper function to find number of nodes
}

//Getter to return data in RootPtr (root of Binary Tree)
template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const {
  return rootPtr->getItem();
}

//Setter to set the data in the RootPtr (root of Binary Tree)
template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem) {
  rootPtr->setItem(newItem);
}

//Function to add a node to the Binary Tree
template <class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {
  auto newPtr = std::make_shared<BinaryNode<ItemType>>(newData);
  rootPtr = balancedAdd(rootPtr, newPtr);	//Uses helper function to balance the tree
  return true;
}

//Clears each node of the Binary Tree
template <class ItemType>
void BinaryNodeTree<ItemType>::clear() {
  std::shared_ptr<BinaryNode<ItemType>> node = rootPtr;
  destroyTree(node);	//Uses helper function to destroy nodes
  rootPtr = nullptr;
}

//Destroys each node of the tree and sets it to NULL
template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr) {
  if (subTreePtr != nullptr) {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    subTreePtr.reset();
    subTreePtr = nullptr;
  }
}

//Traverses Tree in Preorder fashion
template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse() const {
  preorder(rootPtr);
}

//Traverses Tree in inorder fashion
template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse() const {
  inorder(rootPtr);
}

//Traverses Tree in Postorder fashion
template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse() const {
  postorder(rootPtr);
}

//Operator Overload to set two trees equal to each other
template <class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(
    const BinaryNodeTree<ItemType>& rightHandSide) {
  if (this != &rightHandSide) {
    if (rightHandSide.rootPtr) {
      rootPtr = copyTree(rightHandSide.rootPtr);
    }
  }

  return *this;
}

//Helper function to get height of a Binary Tree
template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const {
  if (subTreePtr == nullptr) {
    return 0;
  } else {
    return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                        getHeightHelper(subTreePtr->getRightChildPtr()));
  }
}

//Helper function to get number of nodes
template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(
    int& count, std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const {
  if (subTreePtr) {
    getNumberOfNodesHelper(count, subTreePtr->getLeftChildPtr());
    count++;
    getNumberOfNodesHelper(count, subTreePtr->getRightChildPtr());
  }

  return count;
}

template <class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(
    std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
    std::shared_ptr<BinaryNode<ItemType>> newNodePtr) {
  if (subTreePtr == nullptr) {
    return newNodePtr;
  } else {
    auto leftPtr = subTreePtr->getLeftChildPtr();
    auto rightPtr = subTreePtr->getRightChildPtr();

    if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
      rightPtr = balancedAdd(rightPtr, newNodePtr);
      subTreePtr->setRightChildPtr(rightPtr);
    } else {
      leftPtr = balancedAdd(leftPtr, newNodePtr);
      subTreePtr->setLeftChildPtr(leftPtr);
    }

    return subTreePtr;
  }
}

template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::copyTree(
    const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const {
  std::shared_ptr<BinaryNode<ItemType>> newTreePtr;
  // Copy tree nodes during a preorder traversal
  if (oldTreeRootPtr != nullptr) {
    // Copy node
    newTreePtr = std::make_shared<BinaryNode<ItemType>>(
        oldTreeRootPtr->getItem(), nullptr, nullptr);
    newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
  }  // end if
  // Else tree is empty (newTreePtr is nullptr)
  return newTreePtr;
}  // end copyTree

//Helper to traverse in inorder style
template <class ItemType>
void BinaryNodeTree<ItemType>::inorder(
    std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
  if (treePtr) {
    inorder(treePtr->getLeftChildPtr());
    std::cout << treePtr->getItem() << std::endl;
    inorder(treePtr->getRightChildPtr());
  }
}

//Helper to traverse in preorder style
template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(
    std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
  if (treePtr) {
    std::cout << treePtr->getItem() << std::endl;
    preorder(treePtr->getLeftChildPtr());
    preorder(treePtr->getRightChildPtr());
  }
}

//Helper to traverse postorder
template <class ItemType>
void BinaryNodeTree<ItemType>::postorder(
    std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
  if (treePtr) {
    postorder(treePtr->getLeftChildPtr());
    postorder(treePtr->getRightChildPtr());
    std::cout << treePtr->getItem() << std::endl;
  }
}
