/** Link-based implementation of the ADT binary search tree.
    @file BinarySearchTree.h */

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <memory>
#include "BinaryNode/BinaryNode.h"
#include "BinaryNodeTree/BinaryNodeTree.h"
#include "BinaryTreeInterface/BinaryTreeInterface.h"

template <class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType> {
 private:
  std::shared_ptr<BinaryNode<ItemType>> rootPtr;

 protected:
  //-------------------------------------------------------------
  //      Protected Utility Methods Section:
  //      Recursive helper methods for the public methods.
  //-------------------------------------------------------------
  //  Places a given new node at its proper position in this binary
  //  search tree.
  auto placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                 std::shared_ptr<BinaryNode<ItemType>> newNode);

 public:
  //--------------------------------------------------------------
  //  Constructor and Destructor Section.
  //--------------------------------------------------------------
  BinarySearchTree();
  BinarySearchTree(const ItemType &rootItem);
  BinarySearchTree(const BinarySearchTree<ItemType> &tree);
  virtual ~BinarySearchTree();

  //--------------------------------------------------------------
  //  Public Methods Section.
  //--------------------------------------------------------------
  bool isEmpty() const;
  int getHeight() const;
  int getNumberOfNodes() const;

  ItemType getRootData() const;

  bool add(const ItemType &newEntry);
  void clear();

  //---------------------------------------------------------------
  //  Public Traversals Section.
  //---------------------------------------------------------------
  void preorderTraverse() const;
  void inorderTraverse() const;
  void postorderTraverse() const;

  //---------------------------------------------------------------
  //  Overloaded Operator Section.
  //---------------------------------------------------------------
  BinarySearchTree<ItemType> &operator=(
      const BinarySearchTree<ItemType> &rightHandSide);
};  // end BinarySearchTree

#endif
