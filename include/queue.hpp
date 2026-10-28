#ifndef QUEUE_HPP
#define QUEUE_HPP
#include<iostream>
#include <stdexcept>
using namespace std;
template <class T>
class myQueue{
    private:
        int capacity = 10;
        T* arr = new T[capacity];
        int f,r;
        int size;
    public: 
        myQueue()
        {
            f = -1;
            r = -1;
            size = 0;
        }
        ~myQueue(){
            delete[] arr;
        }
        void enqueue(T val)
        {
            if(f == -1 && r == -1)
            {
                f = r = 0;
                arr[r] = val;
                size++;
            }

            else if( size == capacity )
            {
                int oldCap = capacity;
                capacity *= 2;
                T* Newarr = new T[capacity];

                int i=-1;
                int j = f;
                while( (j+1)%oldCap != rear )
                {
                    i++;
                    Newarr[i] = arr[j];
                    j  = (j+1)%oldCap;
                }
               i++;
               Newarr[i] = arr[j];
                delete[] arr;
                arr = Newarr;
                f = 0;
                r = i;
                r = (r+1)%capacity;
                arr[r] = val;
                size++;
            }

            else{
                r = (r+1)%capacity;
                arr[r] = val;
                size++;
            }
        }

        void dequeue()
        {
            if(size == 0){throw out_of_range("queue is already empty!");}
            else if( size == 1)
            {
                f = -1;
                r = -1;
                size = 0;
            }
            else{ 
                f = (f +1)%capacity;
                size--;
            }
        }
        
        T front()
        {
            if(size == 0){throw out_of_range("queue is empty!");}
            else{
                return arr[f];
            }
        }

        T back()
        {
            if(size == 0){throw out_of_range("queue is empty!");}
            else{
                return arr[rear];
            }
        }

        int size()
        {
            return size;
        }

        void display()
        {
            if(size ==0 ){throw out_of_range("queue is empty!");}
            else
            {
                int i = f;
                while( i != r)
                {
                    cout<<arr[i]<<" ";
                    i = (i+1)%capacity;
                }
                cout<<arr[i]<<endl;
            }
        }
};
#endif