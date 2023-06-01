// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size1>
class TStack {
 private:
    int size;
    int locSize;
    T* arr;

 public:
    TStack() {
      this->size = size1;
      this->arr = new T[size];
      this->locSize = -1;
    }
    ~TStack() {
      delete []arr;
    }
    void push_back(T elem) {
      if (locSize >= size - 1) {
        T* tmp = arr;
        arr = new T[++size];
        for (int i = 0; i < size; i++) arr[i] = tmp[i];
        delete[] tmp;
      }
      arr[++locSize] = elem;
    }
    T& pop_back() {
      size--;
      return arr[--locSize + 1];
    }
    T& getLast() {
      return arr[locSize];
    }
    bool empty() {
      if (locSize == -1) return true;
      else
        return false;
    }
};
#endif  // INCLUDE_TSTACK_H_
