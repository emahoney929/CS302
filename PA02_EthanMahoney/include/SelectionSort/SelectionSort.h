//-------------------------------------------------------------------
//
//      SelectionSort.h
//
//      Header file for Selection Sort Class/Algorithm
//
//-------------------------------------------------------------------
#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include <string>

class SelectionSort  // Selection Sort Class
{
 public:
  SelectionSort(int size);  // Parameterized Ctor
  ~SelectionSort();         // Dtor
  int *getArr();
  int getSize();
  void sort(int *list, int size, int &swaps, int &comps);
  int ReadInput(std::string &infile);
  void WriteToFile(std::string &outfile);

 private:
  int findMax(int *nums, int size,
              int &comps);  // Kept private due to only being a helper for sort
  int *integerArr;
  int size;
};

#endif
