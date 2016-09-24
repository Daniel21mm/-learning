#include <iostream>
#include "myvector.h"
using namespace std;

int main()
{
    MyVector <int> t(3);
    cout << "введите 3 элемента вектора:" << endl;
     cin >> t;
     cout << "полученный вектор" << endl;

    cout <<t << endl;
    t.push_back(5);
    t.push_front(4);
    cout << "после добовления 4 в начало, 5 в конец" << endl;

    cout <<"конец=" << t.back() << " начало= " << t.front() << endl
    <<  " (2 элемент, нум с 0) вектора через at=" << t.at(2) <<endl
    <<" (2 второй, нум с 0) элемент через []="<< t[2] << endl;

    cout << "полученный вектор до сортировки" << endl;

    cout <<t << endl;
t.sorting();
cout << "после сортировки" << endl;

cout <<t << endl;
    t.pop_back();
    t.pop_front();
    cout << "после удаления первого и последнего элемента" << endl;

    cout <<t << endl;
MyVector<int> v(t);
cout << "вектор v скопированный конструктором от t" << endl;

cout << v << endl;
v.push_front(22);
cout << "вектора v и t после добавления (22) в начало v" << endl;


cout << v << endl;
cout <<t << endl;
t=v;
cout << "вектора v и t полсе присваивания (t=v)" << endl;

cout << v << endl;
cout <<t << endl;
    cout << "Hello World!" << endl;
    return 0;
}

