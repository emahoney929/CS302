/** Test Driver file for the ADT binary search tree.
    @file treeTest.cpp */
#include <iostream>
#include <cstdlib>
#include "BinarySearchTree/BinarySearchTree.cpp"
#include "BinaryNode/BinaryNode.cpp"
#include "BinaryNodeTree/BinaryNodeTree.cpp"

using namespace std;

int main()
{
    srand(time(NULL));
    BinarySearchTree<int> tree;
    
    cout << "Binary Tree Traversal Test" << endl;
    cout << "==========================" << endl;
    cout << "Generating Random Number List ";
    cout << "And Adding Them To The Tree" << endl;

    for(int size = 0; size < 100; size++)
    {
        tree.add((rand() % 200) + 1);
    }

    cout << "\n1. Check For An Empty Tree" << endl;
    cout << "===========================" << endl;
    cout << "Is The BST Empty? ";
    cout << boolalpha << tree.isEmpty() << endl;

    cout << "\n2. Check For The Tree Height" << endl;
    cout << "=====================" << endl;
    cout << "The Height of the Tree is: ";
    cout << tree.getHeight() << endl;

    cout << "\n3. Inorder Traversal" << endl;	//Inorder Traversal
    cout << "=====================" << endl;
    tree.inorderTraverse();

    cout << "\n4. Preorder Traversal" << endl;	//Preorder Traversal
    cout << "=====================" << endl;
    tree.preorderTraverse();

    cout << "\n5. Postorder Traversal" << endl;	//Postorder Traversal
    cout << "=====================" << endl;
    tree.postorderTraverse();

    cout << tree.getHeight() << endl;
    cout << tree.getNumberOfNodes() << endl;

    return 0;
}
