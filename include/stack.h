#pragma once
#include <iostream>

template<typename T>
class TStack {
private:
    T* arr;
    int topid;
    int sz;
public:
    TStack(int k=10) {
        if (k > 0) {
            sz = k;
            arr = new T[sz];
            topid = -1;
        }
        else {
            throw ("Invalid Argument");
        }
    }
    TStack(const TStack& s) {
        sz = s.sz;
        arr = new T[sz];
        for (int i = 0; i <= s.topid; ++i) {
            arr[i] = s.arr[i];
        }
        topid = s.topid;
    }
    ~TStack() {
        delete[] arr;
    }
    void push(T el) {
        if (topid >= sz - 1) {
            T* arrtmp = new  T[sz * 2];
            std::copy(arr, arr + sz, arrtmp);
            delete[] arr;
            arr = arrtmp;
            sz *= 2;

        }
        topid++;
        arr[topid] = el;

    }
    T top() {
        if (isEmpty() ) {
            throw ("Stack is empty");
            
        }
        else {
            T res = arr[topid];
            return res;
        }
    }


    void pop() {
        if (isEmpty()) {
            throw ("stack is empty");
        }
        topid--;
    }
    int getSize() {
        return topid + 1;
    }
    bool isEmpty() {
        return topid == -1;
    }
    bool operator==(const TStack& s) {
        bool res = true;
        if (sz != s.sz) {
            res = false;
        }
        else
            for (size_t i = 0; i < sz; i++) {
                if (arr[i] != s.arr[i])
                    res = false;
            }
        return res;
    }

};



