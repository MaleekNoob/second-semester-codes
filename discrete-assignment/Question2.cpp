/*
*Name: Maleek Hussain Ali
*Roll No: 22i-1526
*Section: B
*/
#include <iostream>
#include <string>
using namespace std;


bool isOperator(char c) {
  return (c == '~' || c == '&' || c == '|' || c == '>' || c == '=');
}

bool isVariable(char c) {
  return (c >= 'A' && c <= 'Z')  || (c >= 'a' && c <= 'z');
}

bool Negation(char op, bool val) {
  if (op == '~') {
    return !val;
  }
  else {
    return val;
  }
}

bool evaluate(char op, bool val1, bool val2) {
  if (op == '&') {
    return (val1 && val2);
  }
  else if (op == '|') {
    return (val1 || val2);
  }
  else if (op == '>') {
 
    return (!val1 || val2);
  }
  else if (op == '=') {
    return (val1 == val2);
  }
  else {
    return false;
  }
}

string infixToPostfix(string infix) {
  string postfix = ""; 
  int top = -1; 
  char stack[100];
  for (int i = 0; i < infix.length(); i++) { 
    char c = infix[i];
    if (isVariable(c)) {
      postfix += c;
    }
    else if (isOperator(c)) {
      top++;
      stack[top] = c;
    }
  }
  while (top != -1) {
    postfix += stack[top];
    top--;
  }
  return postfix;
}

bool evalInfix(string infix) {
  string postfix = infixToPostfix(infix);
  bool result;
  int top = -1;
  bool stack[100];
  for (int i = 0; i < postfix.length(); i++) {
    char c = postfix[i];
    if (isVariable(c)) {
      bool val;
      cout << "Enter the value of " << c << " (0 or 1): ";
      cin >> val;
      top++;
      stack[top] = val;
    }
    else if (isOperator(c)) {
      
      if (c == '~') {
        bool val = stack[top];
        top--;
        result = Negation(c, val);
      }
      else {
        bool val2 = stack[top];
        top--;
        bool val1 = stack[top];
        top--;
        result = evaluate(c, val1, val2);
      }
      top++;
    }
  }
  return result;
}

int main() {
  string infix; 
  cout << "Enter a boolean expression in infix notation: ";
  getline(cin, infix); 
  bool result = evalInfix(infix);
  cout << "The expression is ";
  if (result == 0) {
    cout << "false";
  }
  else {
    cout << "true";
  }
  return 0;
}