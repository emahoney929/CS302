/** Link-based header file of the Binary Tree Structure.
    @file BinaryNodeTree.h */

#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include "BinaryNode/BinaryNode.h"
#include "BinaryTreeInterface/BinaryTreeInterface.h"

template <class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
 private:
  std::shared_ptr<BinaryNode<ItemType>> rootPtr;

 protected:
  // PROTECTED UTILITY METHODS SECTION: RECURSIVE HELPER METHODS FOR THE PUBLIC
  // METHODS
  int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
  int getNumberOfNodesHelper(
      int& count, std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

  // Recursively adds a new node to the tree in a left/right fashion to keep
  // tree balanced
  auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                   std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

  // Copies the tree rooted at treePtr and returns a pointer to the root of the
  // copy
  std::shared_ptr<BinaryNode<ItemType>> copyTree(
      const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;

  // Recursively deletes all nodes from the tree
  void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

  // Recursive traversal helper methods
  void preorder(std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
  void inorder(std::shared_ptr<BinaryNode<ItemType>> treePtr) const;
  void postorder(std::shared_ptr<BinaryNode<ItemType>> treePtr) const;

 public:
  // CONSTRUCTOR AND DESTRUCTOR SECTION
  BinaryNodeTree();
  BinaryNodeTree(const ItemType& rootItem);
  BinaryNodeTree(const ItemType& rootItem,
                 const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                 const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
  BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
  virtual ~BinaryNodeTree();

  // PUBLIC BINARY_TREE_INTERFACE METHODS SECTION
  bool isEmpty() const;
  int getHeight() const;
  int getNumberOfNodes() const;
  ItemType getRootData() const;
  void setRootData(const ItemType& newItem);
  bool add(const ItemType& newData);  // Adds an item to the tree
  void clear();

  // PUBLIC TRAVERSAL SECTION
  void preorderTraverse() const;
  void inorderTraverse() const;
  void postorderTraverse() const;

  // OVERLOADED OPERATOR SECTION
  BinaryNodeTree<ItemType>& operator=(
      const BinaryNodeTree<ItemType>& rightHandSide);
};  // end BinaryNodeTree

#endif
