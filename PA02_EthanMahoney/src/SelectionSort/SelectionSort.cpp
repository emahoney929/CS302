//-------------------------------------------------------------------
//
//      SelectionSort.cpp
//
//      Implementation file for Selection Sort Class/Algorithm
//
//-------------------------------------------------------------------

#include "SelectionSort/SelectionSort.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

SelectionSort::SelectionSort(int size)
    : size(size)  // Parameterized Ctor
{
  integerArr = new int[size];  // Allocates the desired amount of data to an
                               // integer array
}

SelectionSort::~SelectionSort()  // Dtor
{
  delete[] integerArr;  // Deletes allocated data and sets pointer to Null
  integerArr = nullptr;
}

int* SelectionSort::getArr()  // Returns a pointer to the front of the Integer
                              // Array
{
  return integerArr;
}

int SelectionSort::getSize()  // Returns the size of the array
{
  return size;
}

void SelectionSort::sort(
    int* list, int size, int& swaps,
    int& comps)  // Main sorting function for Selection Sort Algorithm
{
  for (int i = size - 1; i > 0; i--) {
    int max = findMax(list, i, comps);  // Helper function to find the maximum
                                        // value in a section of the array
    std::swap(list[i],
              list[max]);  // Swaps the max value with the current index in loop
    swaps++;               // Increment counter
  }
}

int SelectionSort::findMax(
    int* nums, int size,
    int& comps)  // Finds the max value in an array of integers
{
  for (int i = size; i >= 0; i--) {
    if (nums[size] <
        nums[i])  // Compares the last value in array to the current index
    {
      size = i;  // If value is greater than max set max index to current index
      comps++;
    }
  }
  return size;  // Returns index to the max value
}

int SelectionSort::ReadInput(std::string &infile)  // Inputs data from file into
                                                   // appropriate data structure
{
  int count = 0;
  std::ifstream inf;
  inf.open("1000Numbers.txt");

  while (count < size && inf) {
    inf >> integerArr[count];
    count++;
  }

  inf.close();
  return count;  // Returns the amount of items read in from the desired file
}

void SelectionSort::WriteToFile(
    std::string &outfile)  // Writes data from array into desired file
{
  std::ofstream outf;
  outf.open(outfile);

  for (int i = 0; i < size; i++) {
    outf << integerArr[i] << std::endl;
  }

  outf.close();
}
