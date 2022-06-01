//@author Ethan Mahoney
//Date: 11/29/2020
//CS 302 - Kostas Alexis
//Purpose: Create an implementation of the Left-Leaning Red Black Search Tree.

#include <signal.h>
#include <iostream>
#include <cstdlib>
#include "LeftLeaningRedBlack/LeftLeaningRedBlack.cpp"
#include "VoidRef.h"



#ifdef USE_MALLOC_MACRO
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


int main()
{
    LeftLeaningRedBlack rbTree;
    VoidRef_t ref[10];
    bool color = false;

    srand(time(NULL));

    for(int i = 0; i < 10; i++)         //Creates 10 random numbers to insert into the tree
    {
        ref[i].Key = rand() % 101;
    }
   
    rbTree.Insert(ref[0]);
    std::cout << "Inserting " << ref[0].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[0].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[0].Key, color))   //Checks to see if a node is red or black
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[0].Key);    //finds the parent of the given child


    rbTree.Insert(ref[1]);
    std::cout << "Inserting " << ref[1].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[1].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[1].Key, color))
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[1].Key);

  
    rbTree.Insert(ref[2]);
    std::cout << "Inserting " << ref[2].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[2].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[2].Key, color))
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[2].Key);
    
    
    rbTree.Insert(ref[3]);
    std::cout << "Inserting " << ref[3].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[3].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[3].Key, color))
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[3].Key);

    std::cout << "Deleting the fourth inserted node " << ref[3].Key << " from the tree\n\n" << std::endl;
    rbTree.Delete(ref[3].Key);
    
    
    rbTree.Insert(ref[4]);
    std::cout << "Inserting " << ref[4].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[4].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[4].Key, color))
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[4].Key);


    rbTree.Insert(ref[5]);
    std::cout << "Inserting " << ref[5].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[5].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[5].Key, color))
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[5].Key);


    rbTree.Insert(ref[6]);
    std::cout << "Inserting " << ref[6].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[6].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[6].Key, color))
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[6].Key);


    rbTree.Insert(ref[7]);
    std::cout << "Inserting " << ref[7].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[7].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[7].Key, color))
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[7].Key);


    rbTree.Insert(ref[8]);
    std::cout << "Inserting " << ref[8].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[8].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[8].Key, color))
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[8].Key);


    rbTree.Insert(ref[9]);
    std::cout << "Inserting " << ref[9].Key << " into the tree" << std::endl;
    std::cout << "The color of " << ref[9].Key << " is ";

    if(rbTree.isRed(rbTree.getRoot(), ref[9].Key, color))
        std::cout << "Red" << std::endl;
    else
        std::cout << "Black" << std::endl;
    
    rbTree.findParent(rbTree.getRoot(), ref[9].Key);


    std::cout << "Displaying the inorder traversal of the tree after the deletion of " << ref[3].Key << std::endl;
    rbTree.Traverse();  //Does an inorder traversal of the tree and displays all the data

    return 0;
}