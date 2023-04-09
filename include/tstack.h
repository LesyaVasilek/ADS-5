// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
   private:
    int v;
    T* mass;
    public:
    TStack() : v(-1) {
        mass = new T[size];
    }
    bool Empty() const {
        return (v == -1);
    }
    bool Full() const {
        return (v == size - 1);
    }
    void push(T num) {
        if (Full()) {
            throw std::string("full!");
        } else {
            mass[++v] = num;
        }
    }
    const T& get() {
        return mass[v];
    }
    const T& pop() {
        if (Empty()) {
            throw std::string("empty!");
        } else {
            return mass[v--];
        }
    }
};
#endif  // INCLUDE_TSTACK_H_
