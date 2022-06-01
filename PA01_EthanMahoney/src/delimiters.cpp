//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include "StackInterface/config.h"

#if LAB6_TEST1
#include "StackLinked/StackLinked.cpp"
#else
#endif

using namespace std;

//--------------------------------------------------------------------

bool delimitersOk(const string &expression);

//--------------------------------------------------------------------

int main() {
  string inputLine;  // Input line

  cout << "This program checks for properly matched delimiters." << endl;

  cout << "Test Cases for Delimiter Expressions:\n"
       << "=======================" << endl;

  // Read in 5 different test cases
  cout << "1. Is the Expression: 4<2^3(1+3{)}[2-1])> valid?" << endl;
  inputLine = delimitersOk("4<2^3(1+3{)}[2-1])>") ? "Valid" : "Invalid";
  cout << inputLine << endl;

  cout << "2. Is the Expression: [8/(4{3*2})] valid?" << endl;
  inputLine = delimitersOk("[8/(4{3*2})]") ? "Valid" : "Invalid";
  cout << inputLine << endl;

  cout << "3. Is the Expression: (4+2-3*4 valid?" << endl;
  inputLine = delimitersOk("(4+2-3*4") ? "Valid" : "Invalid";
  cout << inputLine << endl;

  cout << "4. Is the Expression: 2*3-(1+1) valid?" << endl;
  inputLine = delimitersOk("2*3-(1+1)") ? "Valid" : "Invalid";
  cout << inputLine << endl;

  cout << "5. Is the Expression: (5+2(12/4)-2)-(42-8(1/2)3) valid?" << endl;
  inputLine = delimitersOk("(5+2(12/4)-2)-(42-8(1/2)3)") ? "Valid" : "Invalid";
  cout << inputLine << endl;

  return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below
bool delimitersOk(const string &expression) {
  StackLinked<char> DelimiterStack;

  try {
    for (size_t index = 0; index < expression.length();
         index++) {  // Iterate through expression pushing delimiters
      if (expression[index] == '(' || expression[index] == '[' ||
          expression[index] == '{' || expression[index] == '<') {
        DelimiterStack.push(expression[index]);
      }

      switch (expression[index]) {  // Creates a statement for each closing
                                    // delimiter
        case ')':
          if (DelimiterStack.pop() != '(') return false;
          break;
        case ']':
          if (DelimiterStack.pop() != '[') return false;
          break;
        case '}':
          if (DelimiterStack.pop() != '{') return false;
          break;
        case '>':
          if (DelimiterStack.pop() != '<') return false;
          break;
      }
    }
  } catch (logic_error &e) {  // If a closing delimiter is initially approached,
                              // throw a logic error and return false
    return false;
  }

  return DelimiterStack.isEmpty();
}
