#ifndef STACK_HPP
#define STACK_HPP
#include<iostream>
#include <stdexcept>
#include "vector.hpp"
using namespace std;
template <class T>
class myStack{
    private:
        myVector<T>storage;
    public:
        myStack(){}
        ~myStack(){}
        bool isEmpty(){return storage.isEmpty();}
        T top()
        {
            if(isEmpty){throw out_of_range("stack is empty!");}
            else{return storage[size];}
        }
        void push(T val)
        {
            storage.push_back(val);
        }
        void pop()
        {
            if(storage.isEmpty()){throw out_of_range("Stack is empty!");}
            else{storage.pop_back();}
        }
        int size(){return storage.length();}

        void display()
        {
            int n = storage.length()-1;
            while( n>=0 )
            {
                cout<<storage[n]<<endl;
                n--;
            }
        }
};
#endif