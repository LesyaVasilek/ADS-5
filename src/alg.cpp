// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int status(char n) {
    if (n == '(') return 0;
    if (n == ')') return 1;
    if (n == '+' || n == '-') return 2;
    if (n == '*' || n == '/') return 3;
    return -1;
}
int Int(char c) {
    char n[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for (int i = 0; i < 10; i++) {
        if (c == n[i])
            return i;
    }
    return -1;
}
int L(std::string s) {
    int L = 0;
    char c = s[0];
    while (c != '\0')
        c = s[++L];
    return L;
}
std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stack1;
    std::string r;
    char temp;
    int i = 0;
    char ch = inf[0];
    while (ch != '\0') {
        if (ch >= '0' && ch <= '9') {
            r = r + ch + " ";
        } else if (ch == ')') {
            if (!stack1.Empty()) {
                temp = stack1.pop();
                while (temp != '(') {
                    r = r + temp + " ";
                    temp = stack1.pop();
                }
            }
        } else if ((stack1.Empty()) || ch == '(' || status(ch) >\
                   status(stack1.get())) {
            stack1.push(ch);
        } else if ((!stack1.Empty()) && (status(ch) <= status(stack1.get()))) {
            while ((!stack1.Empty()) && (status(ch) <= status(stack1.get()))) {
                temp = stack1.pop();
                r = r + temp + " ";
            }
            stack1.push(ch);
        }
        ++i;
        ch = inf[i];
    }
    while (!stack1.Empty()) {
        temp = stack1.pop();
        if (stack1.Empty()) r = r + temp;
        else
            r = r + temp + " ";
    }
    return r;
}

int eval(std::string pref) {

    TStack <int, 100> stack2;
    char ch = pref[0];
    int a, b, i = 0, kol = L(pref);
    while (kol) {
        if (ch != ' ') {
            if ((ch >= '0') && (ch <= '9')) {
                stack2.push(Int(ch));
            } else if (!stack2.Empty()) {
                a = stack2.pop();
                b = stack2.pop();
                if (ch == '+') stack2.push(a + b);
                if (ch == '-') stack2.push(b - a);
                if (ch == '*') stack2.push(a * b);
                if (ch == '/') stack2.push(b / a);
            }
        }
        i++;
        ch = pref[i];
        kol--;
    }
    return(stack2.get());
}
