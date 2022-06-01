//---------------------------------------------------------------------------
//
//  postfix.cpp
//
//   Program to evaluate a postfix expression and evaluate it using a Stack
//
//---------------------------------------------------------------------------

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

#include "StackLinked/StackLinked.cpp"

float evalPostfix(const string &expression);

int main() {
  cout << "Postfix Expression Test Cases:\n"
       << "============================" << endl;
  cout << "1. Infix: (3+2)*5/4 Postfix: 32+54/* "
       << "Evaluated is: " << evalPostfix("34+52/*") << endl;
  cout << "2. Infix: 3*(4+5)-7 Postfix: 45+3*7- "
       << "Evaluated is: " << evalPostfix("45+3*7-") << endl;
  cout << "3. Infix: [(8^2*6^4)/9]+7-4  Postfix: 82^64^*9/7+4- "
       << "Evaluated is: " << evalPostfix("82^64^*9/7+4-") << endl;
  cout << "4. Infix: [(3*4)-1)]^(8/2) Postfix: 34*1-82/^ "
       << "Evaluated is: " << evalPostfix("34*1-82/^") << endl;
  cout << "5. Infix: [((4*4)*2)/2]+1*3^2 Postfix: 44*2*2/1+32^- "
       << "Evaluated is: " << evalPostfix("44*2*2/1+32^-") << endl;
  return 0;
}

// Evaluates a postfix expression and calculates the sum.
float evalPostfix(const string &expression) {
  size_t index = 0;
  StackLinked<float> OperandStack;  // Initialize empty stack
  float operand1, operand2, sum;

  while (index < expression.length()) {
    char number = expression[index];
    switch (number) {  // Creates statement for each different operator
      case '+':
        operand1 = OperandStack.pop();
        operand2 = OperandStack.pop();
        sum = operand2 + operand1;
        OperandStack.push(sum);
        break;
      case '-':
        operand1 = OperandStack.pop();
        operand2 = OperandStack.pop();
        sum = operand2 - operand1;
        OperandStack.push(sum);
        break;
      case '*':
        operand1 = OperandStack.pop();
        operand2 = OperandStack.pop();
        sum = operand2 * operand1;
        OperandStack.push(sum);
        break;
      case '/':
        operand1 = OperandStack.pop();
        operand2 = OperandStack.pop();
        sum = operand2 / operand1;
        OperandStack.push(sum);
        break;
      case '^':
        operand1 = OperandStack.pop();
        operand2 = OperandStack.pop();
        sum = pow(operand2, operand1);
        OperandStack.push(sum);
        break;
      default:  // If running into a number, convert it to a float
        number -= '0';
        OperandStack.push(number);
        break;
    }

    index++;
  }

  return OperandStack.pop();  // Returns the last element in the stack (total sum)
}
