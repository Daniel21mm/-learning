#include <iostream>
#include "myvector.h"


int main()
{
    MyVector <int> t(3);

    std::cout << "введите 3 элемента вектора:" << std::endl;
     std::cin >> t;
     std::cout << "полученный вектор" << std::endl;



   std::cout <<t << std::endl;
    t.push_back(5);
    t.push_front(4);
    std::cout << "после добовления 4 в начало, 5 в конец" << std::endl;


    std::cout <<"конец=" << t.back() << " начало= " << t.front() << std::endl
    <<  " (2 элемент, нум с 0) вектора через at=" << t.at(2) <<std::endl
    <<" (2 второй, нум с 0) элемент через []="<< t[2] << std::endl;

    std::cout << "полученный вектор до сортировки" << std::endl;

    std::cout <<t << std::endl;
t.sorting();
std::cout << "после сортировки" << std::endl;

std::cout <<t << std::endl;
    t.pop_back();
    t.pop_front();
   std::cout << "после удаления первого и последнего элемента" << std::endl;

    std::cout <<t << std::endl;
MyVector<int> v(t);
std::cout << "вектор v скопированный конструктором от t" << std::endl;

std::cout << v << std::endl;
v.push_front(22);
std::cout << "вектора v и t после добавления (22) в начало v" << std::endl;


std::cout << v << std::endl;
std::cout <<t << std::endl;
t=v;
std::cout << "вектора v и t полсе присваивания (t=v)" << std::endl;

std::cout << v << std::endl;
std::cout <<t << std::endl;
    std::cout << "Hello World!" << std::endl;

    return 0;
}

