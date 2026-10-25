#ifndef VECTOR_HPP
#define VECTOR_HPP
#include<iostream>
#include <stdexcept>
using namespace std;

template <class T>
class myVector{
    private:
        int size;
        T *arr;
        int capacity;

    public:
        myVector()
        {
            size=0;
            capacity=5;
            arr = new T[capacity];
        }    
        ~myVector(){delete[] arr;}

        void push_back(T value)
        {
            if(size < capacity)
            {
                arr[size] = value;
                size++;
            }
            else if(size == capacity)
            {
                capacity = 2*capacity;
                T* newArr = new T[capacity];
                for(int i=0;i<size;i++)
                    newArr[i] = arr[i];
                delete[]arr;
                arr = newArr;
                arr[size] = value;
                size++;        
            }
        }

        void pop_back()
        {
            if(size == 0)
                return;
            size--;
        }

        int length(){return size;}

        T& operator[](int i)
        { 
            if(i >= size || i < 0)
            {
                throw out_of_range("index is out of range");
            }
            else
                return arr[i];
        }

        void display()
        {
            for(int i=0;i<size;i++)
                cout<<arr[i]<<endl;
        }

        bool isEmpty(){return size==0;}

        T back()
        {
            if(size==0)
                throw out_of_range("Vector is empty");
            return arr[size-1];
        }

        T front()
        {
            if(size==0)
                throw out_of_range("Vector is empty");
            return arr[0];
        }

        void clear()
        {
            size=0;
            // size changes to 0 but the capacity remains the same
        }

        T at(int i)
        {
            if( i<0 || i>=size){
                throw out_of_range("invalid range");
            }
            else{
                return  arr[i];
            }
        }
};

#endif