/** Link-based Interface file of the ADT binary tree.
    @file BinaryTreeInterface.h */

#ifndef BINARY_TREE_INTERFACE_
#define BINARY_TREE_INTERFACE_
#include "BinaryNode/BinaryNode.h"

template <class ItemType>
class BinaryTreeInterface {
 public:
  // Tests whether this binary tree is empty
  // @return True if the binary tree is empty, or false if not
  virtual bool isEmpty() const = 0;

  // Gets the height of this binary tree
  // @return The height of the binary tree
  virtual int getHeight() const = 0;

  // Gets the number of nodes in this binary tree
  // @return The number of nodes in the binary tree
  virtual int getNumberOfNodes() const = 0;

  // Gets the data that is in the root of the binary tree
  // @pre: The binary tree is not empty
  // @post: The root’s data has been returned, binary tree is unchanged
  // @return: The data n the root of the binary tree
  virtual ItemType getRootData() const = 0;

  // Adds the given data to this binary tree
  // @param newData The data to add to the binary tree
  // @post The binary tree contains the new data
  // @return True if the addition is successful, or false if not
  virtual bool add(const ItemType& newData) = 0;

  // Removes all data from this binary tree
  virtual void clear() = 0;

  // Traverses this binary tree in preorder (inorder, postorder) and
  // calls the function visit once for each node
  // @param visit A client-defined function that performs an operation on either
  // each visited node or its data
  virtual void preorderTraverse() const = 0;
  virtual void inorderTraverse() const = 0;
  virtual void postorderTraverse() const = 0;

  // Destroys this tree and frees its assigned memory
  virtual ~BinaryTreeInterface(){};
};  // end BinaryTreeInterface

#endif
