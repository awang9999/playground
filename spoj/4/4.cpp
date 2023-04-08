#include <iostream>
#include <string>
#include <stack>
#include <regex>


using namespace std;

bool isLeftAssociative(char op) {
  if(op == '+'){
    return true;
  } else if (op == '-') {
    return true;
  } else if (op == '*') {
    return true;
  } else if (op == '/') {
    return true;
  } else if (op == '^') {
    return false;
  }

  return true;
}

// Returns true if character is a valid operator, false otherwise
bool isOperator(char maybeOp){
  return (maybeOp == '+' ||
          maybeOp == '-' ||
          maybeOp == '*' ||
          maybeOp == '/' ||
          maybeOp == '^');
}

// Returns true if character is a valid variable. I.e. it matches
// the regex expression [a-z]
bool isVariable(char maybeVar){
  regex e("[a-z]");
  string s(1, maybeVar);
  return regex_match(s, e);
}

// Maps +,-,*,/,^ to 1,2,3,4,5 indicating operator priority levels
// All other inputs are mapped to a negative value.
int priorityOf(char op){
  if(op == '+'){
    return 1;
  } else if (op == '-') {
    return 1;
  } else if (op == '*') {
    return 2;
  } else if (op == '/') {
    return 2;
  } else if (op == '^') {
    return 5;
  }

  return -1;
}

// Returns true if the priority of op1 is >= than the priority of op2.
// Precondition: op1 and op2 are operators.
bool compareOp(char op1, char op2){
  return priorityOf(op1) > priorityOf(op2);
}

void shuntingYard(string expr) {
  stack<char> opstack; 
  
  for (char &c : expr) {
    // Pseudocode
    // If token is a variable, output to cout
    // If token is a operator o1,
    //    while there is a operator, o2 at the top of the opstack that is not
    //          a left paren AND o2 has a greater precedence OR o1 and o2 are
    //          equal precedence and o1 is left-assoc then
    //              pop o2 from the opstack and output it to cout
    //    push o1 to the opstack
    // If token is a left paren, push it to the opstack
    // If token is a right paren,
    //    while the operator at the top of the opstack is not a left paren,
    //          pop the operator and output it to cout
    //    Assert there is a left paren at the top of the opstack
    //    pop the left paren and discard it
    // If there are no more tokens left to read and opstack is nonempty
    //    then pop the remaining operators off the opstack and output them
    //    to cout

    if(isVariable(c)) {
      cout << c;
    } else if (isOperator(c)) {
      while (!opstack.empty() &&
             (compareOp(opstack.top(), c) ||
              (c == opstack.top() && isLeftAssociative(c))
             )
            ) {
        cout << opstack.top();
        opstack.pop();
      }
      opstack.push(c);
    } else if (c == '(') {
      opstack.push(c);
    } else if (c == ')') {
      while(!opstack.empty() && opstack.top() != '(') {
        cout << opstack.top();
        opstack.pop();
      }

      if (opstack.top() == '('){
        opstack.pop();
      }
    }
  }

  while(!opstack.empty()){
    cout << opstack.top();
    opstack.pop();
  }
  
  cout << "\n";
}

int main() {
  int t;
  cin >> t;

  string expr;
  
  for (int i = 0; i < t; ++i) {
    cin >> expr;    
    shuntingYard(expr);
  }
  
  return 0;
}
