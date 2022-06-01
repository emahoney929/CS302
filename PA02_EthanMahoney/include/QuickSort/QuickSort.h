//-------------------------------------------------------------------
//
//      QuickSort.h
//
//      Header file for Quick Sort Class/Algorithm
//
//-------------------------------------------------------------------

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <string>

class QuickSort  // Quick Sort Class
{
 public:
  QuickSort(int size);  // Parameterized Ctor
  ~QuickSort();         // Dtor
  int* getArr();
  int getSize();
  void sort(int* arr, int low, int high, int& swaps, int& comps);
  int ReadInput(std::string &infile);
  void WriteToFile(std::string &outfile);

 private:
  int partition(
      int* arr, int low, int high, int& swaps,
      int& comps);  // Kept private due to only being helper function for sort
  int* integerArr;
  int size;
};

#endif
