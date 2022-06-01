//-------------------------------------------------------------------
//
//      sortTest.cpp
//
//      Main Driver For Testing Sorting Algorithms
//
//-------------------------------------------------------------------

#include <chrono>
#include <string>
#include <iostream>
#include "QuickSort/QuickSort.cpp"
#include "SelectionSort/SelectionSort.cpp"
#define TESTCASES 10  // Value correlates to how many test casese to do

using namespace std;
int main() {
  QuickSort qSort1(1000);
  QuickSort qSort2(10000);
  QuickSort qSort3(100000);
  SelectionSort sSort1(1000);
  SelectionSort sSort2(10000);
  SelectionSort sSort3(100000);
  string digitFile;
  string outFile;
  string infile("Numbers.txt");
  string qsortOutput("QuickSort.txt");
  string ssortOutput("SelectionSort.txt");
  int swapCount;
  int comparisonCount;
  int timeSum;  // Variable used to store the total time it takes to execute a
                // sort

  // Test Cases for the Quick Sort Algorithm
  cout << "Tests for Quick Sort\n"
       << "================================" << endl;
  cout << "Test 1: Sorting 1000 Digits" << endl;  // Testing 1000 Integers
  timeSum = 0;
  swapCount = 0;
  comparisonCount = 0;
  digitFile = to_string(
      qSort1.getSize());  // Creates the string for the 1000 digit input file
  digitFile = digitFile + infile;
  outFile = to_string(
      qSort1.getSize());  // Creates the string for the 1000 digit output file
  outFile += qsortOutput;

  for (int i = 0; i < TESTCASES; i++)  // Loop to run test cases
  {
    qSort1.ReadInput(digitFile);
    auto start = chrono::high_resolution_clock::now();  // Uses chrono library
                                                        // to record CPU time
    qSort1.sort(qSort1.getArr(), 0, qSort1.getSize(), swapCount,
                comparisonCount);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    timeSum += duration.count();
  }

  // Displays average results of the test cases
  cout << "\tAverage Swap Count For 10 Cases: " << swapCount / TESTCASES
       << endl;
  cout << "\tAverage Comparison Count for 10 Cases: "
       << comparisonCount / TESTCASES << endl;
  cout << "\tAverage CPU Time For 10 Cases: " << timeSum / TESTCASES
       << " microseconds" << endl;

  qSort1.WriteToFile(outFile);

  cout << "\nTest 2: Sorting 10000 Digits" << endl;  // Test for 10000 Integers
  timeSum = 0;  // Resets the counts after each test
  swapCount = 0;
  comparisonCount = 0;
  digitFile = to_string(
      qSort2.getSize());  // Creates the string for the 10000 digit input file
  digitFile = digitFile + infile;
  outFile = to_string(
      qSort2.getSize());  // Creates the string for the 10000 digit output file
  outFile += qsortOutput;

  for (int i = 0; i < TESTCASES; i++) {
    qSort2.ReadInput(digitFile);
    auto start = chrono::high_resolution_clock::now();
    qSort2.sort(qSort2.getArr(), 0, qSort2.getSize(), swapCount,
                comparisonCount);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    timeSum += duration.count();
  }

  // Test Case results for the 10000 Integers
  cout << "\tAverage Swap Count For 10 Cases: " << swapCount / TESTCASES
       << endl;
  cout << "\tAverage Comparison Count for 10 Cases: "
       << comparisonCount / TESTCASES << endl;
  cout << "\tAverage CPU Time For 10 Cases: " << timeSum / TESTCASES
       << " microseconds" << endl;

  qSort2.WriteToFile(outFile);  // input the sorted list of 10000 Integers into
                                // the appropriate file

  cout << "\nTest 3: Sorting 100000 Digits"
       << endl;  // Test Case for 100000 Integers
  timeSum = 0;
  swapCount = 0;
  comparisonCount = 0;
  digitFile = to_string(qSort3.getSize());
  digitFile = digitFile + infile;
  outFile = to_string(qSort3.getSize());
  outFile += qsortOutput;

  for (int i = 0; i < TESTCASES;
       i++)  // Loop to execute the amount of Test Cases
  {
    qSort3.ReadInput(digitFile);
    auto start = chrono::high_resolution_clock::now();
    qSort3.sort(qSort3.getArr(), 0, qSort3.getSize(), swapCount,
                comparisonCount);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    timeSum += duration.count();
  }

  // Test Case results for the 100000 Integers
  cout << "\tAverage Swap Count For 10 Cases: " << swapCount / TESTCASES
       << endl;
  cout << "\tAverage Comparison Count for 10 Cases: "
       << comparisonCount / TESTCASES << endl;
  cout << "\tAverage CPU Time For 10 Cases: " << timeSum / TESTCASES
       << " microseconds" << endl;

  qSort3.WriteToFile(outFile);

  // Test Cases for the Selection Sort Algorithm
  cout << "\n\nTests for Selection Sort\n"
       << "================================" << endl;
  cout << "Test 1: Sorting 1000 Digits" << endl;  // Test for 1000 Integers
  timeSum = 0;
  swapCount = 0;
  comparisonCount = 0;
  digitFile = to_string(sSort1.getSize());
  digitFile = digitFile + infile;
  outFile = to_string(sSort1.getSize());
  outFile += ssortOutput;

  for (int i = 0; i < TESTCASES; i++) {
    sSort1.ReadInput(digitFile);
    auto start = chrono::high_resolution_clock::now();
    sSort1.sort(sSort1.getArr(), sSort1.getSize(), swapCount, comparisonCount);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    timeSum += duration.count();
  }

  // Average Results of 1000 Integers Test Case
  cout << "\tAverage Swap Count For 10 Cases: " << swapCount / TESTCASES
       << endl;
  cout << "\tAverage Comparison Count for 10 Cases: "
       << comparisonCount / TESTCASES << endl;
  cout << "\tAverage CPU Time For 10 Cases: " << timeSum / TESTCASES
       << " microseconds" << endl;

  sSort1.WriteToFile(outFile);

  cout << "\nTest 2: Sorting 10000 Digits"
       << endl;  // Test Case for 10000 Integers
  timeSum = 0;
  swapCount = 0;
  comparisonCount = 0;
  digitFile = to_string(sSort2.getSize());
  digitFile += infile;
  outFile = to_string(sSort2.getSize());
  outFile += ssortOutput;

  for (int i = 0; i < TESTCASES; i++) {
    sSort2.ReadInput(digitFile);
    auto start = chrono::high_resolution_clock::now();
    sSort2.sort(sSort2.getArr(), sSort2.getSize(), swapCount, comparisonCount);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    timeSum += duration.count();
  }

  // Average Results for the 10000 Integer Test Case
  cout << "\tAverage Swap Count For 10 Cases: " << swapCount / TESTCASES
       << endl;
  cout << "\tAverage Comparison Count for 10 Cases: "
       << comparisonCount / TESTCASES << endl;
  cout << "\tAverage CPU Time For 10 Cases: " << timeSum / TESTCASES
       << " microseconds" << endl;

  sSort2.WriteToFile(outFile);

  cout << "\nTest 3: Sorting 100000 Digits"
       << endl;  // Test Case for 100000 Integers
  timeSum = 0;
  swapCount = 0;
  comparisonCount = 0;
  digitFile = to_string(sSort3.getSize());
  digitFile += infile;
  outFile = to_string(sSort3.getSize());
  outFile += ssortOutput;

  for (int i = 0; i < TESTCASES; i++) {
    sSort3.ReadInput(digitFile);
    auto start = chrono::high_resolution_clock::now();
    sSort3.sort(sSort3.getArr(), sSort3.getSize(), swapCount, comparisonCount);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    timeSum += duration.count();
  }

  // Average Results for the 100000 Integer Test Case
  cout << "\tAverage Swap Count For 10 Cases: " << swapCount / TESTCASES
       << endl;
  cout << "\tAverage Comparison Count for 10 Cases: "
       << comparisonCount / TESTCASES << endl;
  cout << "\tAverage CPU Time For 10 Cases: " << timeSum / TESTCASES
       << " microseconds" << endl;

  sSort3.WriteToFile(outFile);

  return 0;
}
