//-------------------------------------------------------------------
//
//      QuickSort.cpp
//
//      Implementation file for the Quick Sort Class/Algorithm
//
//-------------------------------------------------------------------

#include "QuickSort/QuickSort.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

QuickSort::QuickSort(int size)
    : size(size)  // Initializes the array with enough space for integers
{
  integerArr = new int[size];
}

int* QuickSort::getArr()  // Returns a pointer to the beginning of the integer
                          // array
{
  return integerArr;
}

int QuickSort::getSize()  // Returns the size of the array of integers
{
  return size;
}

QuickSort::~QuickSort()  // Deletes the allocated data inside the integer
                         // pointer
{
  delete[] integerArr;
  integerArr = nullptr;
}

void QuickSort::sort(int* arr, int low, int high, int& swaps,
                     int& comps)  // Main function of QuickSort Algorithm
{
  if (low < high) {
    int p = partition(arr, low, high, swaps,
                      comps);  // Partitions the array and returns the value of
                               // the spot to partition
    sort(arr, low, p, swaps, comps);  // Recursively splits the array into
                                      // smaller parts on the lower half
    sort(arr, p + 1, high, swaps, comps);  // Recursively splits the array into
                                           // smaller parts on the upper half
  }
}

int QuickSort::partition(
    int* integers, int low, int high, int& swaps,
    int& comps)  // Sorts array into smaller and larger halfs using middle pivot
{
  int mid = low + (high - low) / 2;
  int pivot =
      integers[mid];  // Sets pivot to the value in the middle of the array
  int rightInd = high;
  int leftInd = low;
  bool done = false;

  while (!done) {
    while (integers[leftInd] < pivot)  // Compares pivot to left half of array
    {
      leftInd++;
      comps++;
    }

    while (integers[rightInd] > pivot)  // Compares pivot to right half of array
    {
      rightInd--;
      comps++;
    }

    if (leftInd < rightInd) {
      std::swap(integers[leftInd],
                integers[rightInd]);  // swaps the values found from the left
                                      // and right half
      swaps++;  // Increment the swap counter
      comps++;  // Increment the Comparison counter
      rightInd--;
      leftInd++;
    } else
      done = true;
  }
  return rightInd;
}

int QuickSort::ReadInput(std::string &infile)  // Reads integers from desired
                                              // file and saves them in array
{
  int count = 0;
  std::ifstream inf;
  inf.open(infile);

  while (count < size && inf) {
    inf >> integerArr[count];
    count++;
  }

  inf.close();

  return count;  // Returns the amount of items were read from file
}

void QuickSort::WriteToFile(
    std::string &outfile)  // Writes data in array into the desired output file
{
  std::ofstream outf;
  outf.open(outfile);

  for (int i = 0; i < size; i++) {
    outf << integerArr[i] << std::endl;
  }

  outf.close();
}
