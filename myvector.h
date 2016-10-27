#ifndef MYVECTOR
#define MYVECTOR

#include "myexcept.h"

#include <iostream>


template<typename T>
class MyVector;

template<typename T>
std::ostream & operator <<(std::ostream &, const MyVector<T> &);

template<typename T>
std::istream & operator >>(std::istream &, MyVector<T> &);

template<typename T>
class MyVector
{
    T* element;
    int _end;
    int _size;
public:
    MyVector() throw (MyExcept);
    MyVector(int)throw (MyExcept);
    MyVector(const MyVector<T>&)throw (MyExcept);
    int size();
    T& at(int) throw (MyExcept);
    T& front();
    void push_front(T);
    void pop_front();
    T& back();
    void push_back(T);
    void pop_back();
    void sorting(); // сортировка выбором
    T& operator [](int)throw (MyExcept);
    MyVector<T>& operator+ (MyVector<T>& v);
    MyVector<T>& operator- (MyVector<T>& v);
    friend std::ostream& operator << <T>(std::ostream&,const MyVector<T>&);
    friend std::istream& operator >> <T>(std::istream& ,MyVector<T>&);
    MyVector<T>& operator= (const MyVector<T>&);
    ~MyVector();
};

template<typename T>
MyVector<T>::MyVector()throw (MyExcept) //bad_alloc
    :_end(0),_size(10)
{
    try
    {
        element = new T[_size];
    }
    catch(std::bad_alloc &ba)
    {
        throw MyExcept("bad alloc");
    }

}

template<typename T>
MyVector<T>::MyVector(int _size) throw (MyExcept) //(std::bad_alloc)
{
    this->_end=_size;
    this->_size=_size*2;
    try
    {

        element = new T[_size];
    }
    catch(std::bad_alloc &ba)
    {
        throw MyExcept("bad alloc");

    }


}



template<typename T>
MyVector<T>::MyVector(const MyVector<T> &v) throw (MyExcept)// (std::bad_alloc)
    :_size(v._size),_end(v._end)
{
    try
    {
        element= new T[_size];
        for(int i(0);i<_end;i++)
        {
            element[i]=v.element[i];
        }
    }
    catch(std::bad_alloc &b)
    {
        throw MyExcept("bad alloc");
    }

}

template<typename T>
int MyVector<T>::size()
{
    return _end;
}

template<typename T>
T& MyVector<T>::at(int index)  throw (MyExcept)//(std::out_of_range)
{
    if(index<_end && index>-1)
    {
        return element[index];
    }
    else
    {

        throw MyExcept("out_of_range");

    }


}
template<typename T>
T& MyVector<T>::front()
{
    return element[0];
}

template<typename T>
void MyVector<T>::push_front(T t)
{
    _size++;
    _end++;
    T* ptr= new T[_size];
    ptr[0]=t;
    for(int i(0);i<_end;i++)
    {
        ptr[i+1]=element[i];
    }
    delete [] element;
    element=ptr;
    ptr=nullptr;

}

template<typename T>
void MyVector<T>::pop_front()
{
    if(_end!=0)
    {
        _end--;
        T* ptr =new T[_size];
        for(int i(0);i<_end;i++)
        {
            ptr[i]=element[i+1];
        }
        delete [] element;
        element=ptr;
        ptr=nullptr;

    }
    else
    {
        throw MyExcept("vector empty");
    }

}

template<typename T>
T& MyVector<T>::back()
{
    return  element[_end-1];
}

template<typename T>
void MyVector<T>::push_back(T t)
{
    if(_end!=_size)
    {
        element[_end]=t;
        _end++;
    }
    else
    {
        _end++;
        _size*=2;
        T* ptr =new T[_size];
        delete[] element;
        element=ptr;
        element[_end]=t;

        ptr=nullptr;

    }

}

template<typename T>
void MyVector<T>::pop_back()
{

    if(_end!=0)
    {
        _end--;
    }
    else
    {
        throw MyExcept("vector emtpy");
    }
}

template<typename T>
void MyVector<T>::sorting()
{
    int min;
    for(int i(0);i<_end-1;i++)
    {
        min=i;
        for(int j(min+1);j<_end;j++)
        {
            if(element[min]>element[j])
            {
                min=j;
            }
        }

        if(min != i)
        {
            T tmp=element[i];
            element[i]=element[min];
            element[min]=tmp;
            //выносить в вункцию или использовать арифметический метод мне лень)

        }
    }
}

template<typename T>
T& MyVector<T>::operator [](int index) throw (MyExcept)//(std::out_of_range)

{
    if(index<_end && index>-1)
    {
        return element[index];
    }
    else
    {

        throw MyExcept("ошибка диапозона/Range error in my vector");

    }
}

template<typename T>
MyVector<T> &MyVector<T>::operator+(MyVector<T> &v)
{
    if(_end>=v._end)
    {
        for(int i(0);i<v._end;i++)
        {
            element[i]+=v.element[i];
        }
    }
    else
    {
        for(int i(0);i<_end;i++)
        {
            element[i]+=v.element[i];
        }
        for(int i(_end);i<(v._end);i++)
        {
            push_back(v.element[i]);
        }

    }
    return *this;
}

template<typename T>
MyVector<T> &MyVector<T>::operator-(MyVector<T> &v)
{
    if(_end>=v._end)
    {
        for(int i(0);i<v._end;i++)
        {
            element[i]-=v.element[i];
        }
    }
    else
    {
        for(int i(0);i<_end;i++)
        {
            element[i]-=v.element[i];
        }
        for(int i(_end);i<(v._end);i++)
        {
            push_back(-v.element[i]);
        }

    }
    return *this;
}


template<class T>
std::ostream& operator <<(std::ostream& os,const MyVector<T>& v)
{

    for(int i(0);i<v._end;i++)
    {
        os << v.element[i] << " ";
    }
    return os;
}

template<class T>
std::istream& operator >> (std::istream& is ,MyVector<T>& v)
{
    for(int i(0);i<v._end;i++)
    {
        is >> v.element[i];
    }
    return is;
}

template<typename T>
MyVector<T>& MyVector<T>::operator =(const  MyVector<T>& v)
{

    _end=v._end;
    _size=v._size;
    try
    {
        element= new T[_size];
        for(int i(0);i<_end;i++)
        {
            element[i]=v.element[i];
        }
        return *this;
    }
    catch(std::bad_alloc &b)
    {
        throw MyExcept("bad alloc");
    }


}



template<typename T>
MyVector<T>::~MyVector()
{
    delete[] element;

}


#endif // MYVECTOR

