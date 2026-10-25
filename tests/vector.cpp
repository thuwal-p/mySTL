#include<iostream>
#include "../include/vector.hpp"

using namespace std;
int main(){
    myVector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.display();
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    cout<<"Again after inserting :"<<endl;
    v.display();
    v.pop_back();
    v.pop_back();
    cout<<"after poping: "<<endl;
    v.display();
    //v.clear();
    cout<<"size= "<<v.length()<<endl;
    v.isEmpty() ? (cout<<"its empty"<<endl):(cout<<"its not empty."<<endl);
    try
    {
        cout<<"front element= "<<v.front()<<endl;
    }
    catch(std::out_of_range& e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        cout<<"back element= "<<v.back()<<endl;
    }
    catch(std::out_of_range& e)
    {
        cerr << e.what() << endl;
    }
    try
    {
        cout<<v[2]<<endl;
        v[2] = 100;
        cout<<v[2]<<endl;
        cout<<v[100];
    }
    catch(out_of_range&e){cerr<< e.what() << endl;}
    v.display();
    cout<<v.at(3);
}