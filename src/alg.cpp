// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int prioritet (char value) {
  switch (value) {
      case '(':
      return 0;
      break;
      case ')':
      return 1;
      break;
      case '+':
      return 2;
      break;
      case '-':
      return 2;
      break;
      case '*':
      return 3;
      break;
      case '/':
      return 3;
      break;
      default:
      return -1;
      }
  }
std::string infx2pstfx(std::string inf) {
 std::string pfx;
  int i = 0;
  char chv = inf[i];
  char arr = 0;
  TStack <char> stackChar;
  while (chv) {
    int priority;
    priority = prior(chv);
    if (priority > -1) {
      if ((priority == 0 || priority > prior(arr) ||
           stackChar.isEmpty()) && chv != ')') {
        if (stackChar.isEmpty())
          arr = chv;
        stackChar.push(chv);
        }
      else if (chv == ')') {
        while (stackChar.get() != '(') {
          pfx.push_back(stackChar.get());
          pfx.push_back(' ');
          stackChar.pop();
          }
        stackChar.pop();
        if (stackChar.isEmpty())
          arr = 0;
        }
      else {
        while (!stackChar.isEmpty() &&
               prior(stackChar.get()) >= priority) {
          pfx.push_back(stackChar.get());
          pfx.push_back(' ');
          stackChar.pop();
  }
        if (stackChar.isEmpty())
          arr = chv;
        stackChar.push(chv);
        }
      }
    else {
      pfx.push_back(chv);
      pfx.push_back(' ');
}
    chv = inf[++i];
    }
  while (!stackChar.isEmpty()) {
    pfx.push_back(stackChar.get());
    pfx.push_back(' ');
    stackChar.pop();
    }
  pfx.erase(pfx.end() - 1, pfx.end());
  return pfx;
  }
int eval(std::string pst) {
 std::string tstr;
TStack<int> stack2;
for (int i = 0; i < pst.length(); i++) {
  if (pst[i] >= '0' && pst[i] <= '9') {
    tstr = pst[i];
    stack2.push(pst[i] - '0');
    }
  else if (pst[i] != ' ') {
    int second = stack2.get();
    stack2.pop();
    int first = stack2.get();
    stack2.pop();
    if (pst[i] == '*') stack2.push(first * second);
    else if (pst[i] == '/') stack2.push(first / second);
    else if (pst[i] == '+') stack2.push(first + second);
    else {
      stack2.push(first - second);
      }
    }
  return stack2.get();
  }
