#ifndef MYVECTOR
#define MYVECTOR

#include <stdexcept>
#include  <exception>


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
    int _size;
public:
    MyVector() throw (std::bad_alloc);
    MyVector(int)throw (std::bad_alloc);
    MyVector(const MyVector<T>&)throw (std::bad_alloc);
    int size();
    T& at(int) throw (std::out_of_range);
    T& front();
    void push_front(T);
    void pop_front();
    T& back();
    void push_back(T);
    void pop_back();
    void sorting(); // сортировка выбором
    T& operator [](int)throw (std::out_of_range);
    MyVector<T>& operator+ (MyVector<T>& v);
    MyVector<T>& operator- (MyVector<T>& v);
    friend std::ostream& operator << <T>(std::ostream&,const MyVector<T>&);
    friend std::istream& operator >> <T>(std::istream& ,MyVector<T>&);
    MyVector<T>& operator= (const MyVector<T>&);
};

template<typename T>
MyVector<T>::MyVector()throw (std::bad_alloc)
    :_size(0)
{
    try
    {
       element = new T;
    }
    catch(std::bad_alloc &b)
    {
        throw std::bad_alloc(b);
    }

}

template<typename T>
MyVector<T>::MyVector(int _size) throw (std::bad_alloc)
{
    this->_size=_size;
    try
    {
     element = new T[_size];
    }
    catch(std::bad_alloc &b)
    {
        throw std::bad_alloc(b);

    }
    for(int i(0);i<_size;i++)
    {
        element[i]=0;
    }



}

template<typename T>
MyVector<T>::MyVector(const MyVector<T> &v) throw (std::bad_alloc)
    :_size(v._size)
{
    try
    {
     element= new T[v._size];
    }
    catch(std::bad_alloc &b)
    {
        throw std::bad_alloc(b);
    }
    for(int i(0);i<_size;i++)
    {
        element[i]=v.element[i];
    }
}

template<typename T>
int MyVector<T>::size()
{
    return _size;
}

template<typename T>
T& MyVector<T>::at(int index) throw (std::out_of_range)
{
    if(index<_size)
    {
        return element[index];
    }
    else
    {

        throw std::out_of_range("ошибка диапозона/Range error in my vector");

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
    MyVector<T> v(_size+1);
    v.element[0]=t;
    for(int i(1);i<_size+1;i++)
    {
        v.element[i]=element[i-1];
    }

    delete [] element;
    element= v.element;
    _size=v._size;
}

template<typename T>
void MyVector<T>::pop_front()
{
    MyVector<T> v(_size-1);
    for(int i(0);i<_size-1;i++)
    {
        v.element[i]=element[i+1];
    }
    delete [ ] element;
    element =v.element;
    _size = v._size;
}

template<typename T>
T& MyVector<T>::back()
{
    return  element[_size-1];
}

template<typename T>
void MyVector<T>::push_back(T t)
{
    MyVector v(_size+1);
    v.element[_size]=t;

    for(int i(0);i<_size;i++)
    {
        v.element[i]=element[i];
    }

    delete [] element;
    element= v.element;
    _size=v._size;
}

template<typename T>
void MyVector<T>::pop_back()
{
    MyVector<T> v(_size-1);
    for(int i(0);i<_size-1;i++)
    {
        v.element[i]=element[i];
    }
    delete [] element;
    element =v.element;
    _size = v._size;
}

template<typename T>
void MyVector<T>::sorting()
{
    int min;
    for(int i(0);i<_size-1;i++)
    {
        min=i;
        for(int j(min+1);j<_size;j++)
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
T& MyVector<T>::operator [](int index) throw (std::out_of_range)
{
    if(index<_size)
    {
        return element[index];
    }
    else
    {
        throw std::out_of_range("ошибка диапозона/Range error in my vector");

    }
}

template<typename T>
MyVector<T> &MyVector<T>::operator+(MyVector<T> &v)
{
    if(_size>=v._size)
    {
        for(int i(0);i<v._size;i++)
        {
            element[i]+=v.element[i];
        }
    }
    else
    {
        for(int i(0);i<_size;i++)
        {
            element[i]+=v.element[i];
        }
        for(int i(_size);i<(v._size);i++)
        {
            push_back(v.element[i]);
        }

    }
    return *this;
}

template<typename T>
MyVector<T> &MyVector<T>::operator-(MyVector<T> &v)
{
    if(_size>=v._size)
    {
        for(int i(0);i<v._size;i++)
        {
            element[i]-=v.element[i];
        }
    }
    else
    {
        for(int i(0);i<_size;i++)
        {
            element[i]-=v.element[i];
        }
        for(int i(_size);i<(v._size);i++)
        {
            push_back(-v.element[i]);
        }

    }
    return *this;
}


template<class T>
std::ostream& operator <<(std::ostream& os,const MyVector<T>& v)
{

    for(int i(0);i<v._size;i++)
    {
        os << v.element[i] << " ";
    }
    return os;
}

template<class T>
std::istream& operator >> (std::istream& is ,MyVector<T>& v)
{
    for(int i(0);i<v._size;i++)
    {
        is >> v.element[i];
    }
    return is;
}

template<typename T>
MyVector<T>& MyVector<T>::operator =(const  MyVector<T>& v)
{

    element=v.element;
    _size=v._size;

    return *this;
}



#endif // MYVECTOR

