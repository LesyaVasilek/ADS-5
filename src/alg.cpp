// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char const sym) {
  switch (sym) {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
  }
  return -1;
}
std::string infx2pstfx(std::string inf) {
  std::string result = "";
  int i = 0;
  TStack <char, 5> fstack;
  while (i < inf.length()) {
    if (priority(inf[i]) == -1) {
      result += inf[i];
      i++;
    } else if (priority(inf[i]) == 2 || priority(inf[i]) == 3) {
      if (fstack.empty() || fstack.getLast() == '(') {
        fstack.push_back(inf[i]);
        result += " ";
        i++;
      } else if (priority(inf[i]) > priority(fstack.getLast())) {
        fstack.push_back(inf[i]);
        result += " ";
        i++;
      } else if (priority(inf[i]) <= priority(fstack.getLast())) {
        result += " ";
        result += fstack.pop_back();
        result += " ";
        while ((priority(inf[i]) <= priority(fstack.getLast()) ||
                fstack.getLast() != '(') && !fstack.empty()) {
          result += " ";
          result += fstack.pop_back();
          result += " ";
        }
        fstack.push_back(inf[i]);
        i++;
      }
    } else if (priority(inf[i]) == 0) {
      fstack.push_back(inf[i]);
      i++;
    } else if (priority(inf[i]) == 1) {
      while (fstack.getLast() != '(') {
        result += " ";
        result += fstack.pop_back();
      }
      fstack.pop_back();
      i++;
    }
  }
  while (!fstack.empty()) {
    result += " ";
    result += fstack.pop_back();
  }
  return result;
}
int res(std::string first, std::string second, char oper) {
  int num1 = 0;
  int num2 = 0;
  num1 = stoi(first);
  num2 = stoi(second);
  switch (oper) {
    case '+': return num1 + num2;
    case'-': return  num1 - num2;;
    case '*': return  num1 * num2;;
    case'/':return  num1 / num2;
  }
  return 0;
}
int operat(int first, int second, char oper) {
  switch (oper) {
    case '+': return first + second;
    case'-': return  first - second;;
    case '*': return  first * second;;
    case'/':return  first / second;
  }
  return 0;
}
int res(std::string first) {
  return stoi(first);
}
int eval(std::string pref) {
  TStack <int, 5> sstack;
  int i = 0;
  std::string number;
  int first;
  int second;
  while (i < pref.size()) {
    if (priority(pref[i]) == -1 && pref[i] != ' ') {
      number = pref[i];
      sstack.push_back(res(number));
    } else if (priority(pref[i]) == 2 || priority(pref[i]) == 3) {
      second = sstack.pop_back();
      first = sstack.pop_back();
      sstack.push_back(operat(first, second, pref[i]));
    }
    i++;
  }
  return sstack.pop_back();
}
