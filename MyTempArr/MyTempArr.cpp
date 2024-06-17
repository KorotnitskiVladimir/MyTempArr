#include <complex.h>
#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T* arr;
    int size;
public:
    Array();
    Array(int s);
    ~Array();
    Array(const Array& obj);
    void setArr(T* a);
    int getSize() const;
    void print() const;
    void initRand();
    void setSize(int s, int g);
    int getUpperBond();
    bool isEmpty();
    void freeExtra();
    void removeAll();
    T operator[](int ind);
    T operator[](int ind) const;
    T getAt(int ind) const;
    void setAt(T val, int ind);
    void Add(T val);
    void append(const Array &obj);
    Array& operator=(const Array& obj);
    T* getData() const;
    void insertAt(T val, int ind);
    void removeAt(int ind);
};

template <class T>
Array<T>::Array()
{
    arr = nullptr;
    size = NULL;
}

template <class T>
Array<T>::Array(int s)
{
    size = s;
    arr = new T[size];
    for (int i=0; i<size; i++)
        arr[i] = NULL;
}

template <class T>
Array<T>::~Array()
{
    if (arr)
        delete [] arr;
}

template <class T>
Array<T>::Array(const Array& obj)
{
    this->size = obj.size;
    this->arr = new T[this->size];
    for (int i=0; i<this->size; i++)
        this->arr[i] = obj.arr[i];
}

template <class T>
void Array<T>::setArr(T* a)
{
    if (arr)
        delete [] arr;
    arr = a;
}

template <class T>
int Array<T>::getSize() const
{
    return size;
}

template <class T>
void Array<T>::print() const
{
    if (arr)
    {
        for (int i=0; i<size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
        cout << "nullptr" << endl;
}

template <class T>
void Array<T>::initRand()
{
    if (arr)
    {
        for (int i=0; i<size; i++)
            arr[i] = rand()%(100+1) * 1.2;
    }
    else
        cout << "no matching object to call function" << endl;
 }

template <class T>
void Array<T>::setSize(int s, int g)
{
    if (arr)
    {
        int t = size;
        if (s>size)
        {
            while(s>size)
                size+=g;
            T* temp = new T[size];
            for (int i=0; i<t; i++)
                temp[i] = arr[i];
            for (int i=t; i<size; i++)
                temp[i] = NULL;
            delete [] arr;
            arr = temp;
        }
        else if (s<size)
        {
            T* temp = new T[s];
            for (int i=0; i<s; i++)
                temp[i] = arr[i];
            delete [] arr;
            arr = temp;
            size = s;
        }
    }
    else
        cout << "no matching object to call function" << endl;
}

template <class T>
int Array<T>::getUpperBond()
{
    if (arr)
    {
        int ind = 0;
        if (arr[size-1]!=NULL)
            ind = size-1;
        if (arr[0]!=NULL)
        {
            for (int i=0; i<size; i++)
                if (arr[i]==NULL)
                {
                    ind = i-1;
                    break;
                }
        }
        return ind;
    }
    else
        return -1;
}

template <class T>
bool Array<T>::isEmpty()
{
    if (getUpperBond() == 0)
        return true;
    else
        return false;
}

template <class T>
void Array<T>::freeExtra()
{
    if (arr)
    {
        if (getUpperBond()<size-1)
        {
            int s = getUpperBond()+1;
            T* temp = new T[s];
            for (int i=0; i<s; i++)
                temp[i] = arr[i];
            delete [] arr;
            arr = temp;
            size = s;
        }
    }
    else
        cout << "no matching object to call function" << endl;
}

template <class T>
void Array<T>::removeAll()
{
    arr = nullptr;
}

template <class T>
T Array<T>::operator[](int i)
{
    return arr[i];
}

template <class T>
T Array<T>::operator[](int ind) const
{
    return arr[ind];
}

template <class T>
T Array<T>::getAt(int ind) const
{
    return arr[ind];
}

template <class T>
void Array<T>::setAt(T val, int ind)
{
    if (ind<=size-1)
    {
        T* temp = new T[size];
        for (int i=0; i<ind; i++)
            temp[i] = arr[i];
        temp[ind] = val;
        for (int i=ind+1; i<size; i++)
            temp[i] = arr[i];
        delete [] arr;
        arr = temp;
    }
    else
        cout << "index is out of range" << endl;
}

template <class T>
void Array<T>::Add(T val)
{
    if (getUpperBond()<size-1)
        setAt(val, getUpperBond()+1);
    else
    {
        int s = ++size;
        setSize(s, 1);
        setAt(val, size-1);
    }
}

template <class T>
void Array<T>::append(const Array& obj)
{
    if (this->arr && obj.arr)
    {
        int s = this->size + obj.size;
        T* temp = new T[s];
        for (int i=0; i<this->size; i++)
            temp[i] = this->arr[i];
        for (int i=this->size, j=0; j<obj.size; i++, j++)
            temp[i] = obj.arr[j];
        delete [] this->arr;
        this->size = s;
        arr = temp;
    }
}

template <class T>
Array<T>& Array<T>::operator=(const Array& obj)
{
    if (this->arr == obj.arr)
        return *this;
    if (this->arr)
        delete [] this->arr;
    this->size = obj.size;
    this->arr = new T[this->size];
    for (int i=0; i<this->size; i++)
        this->arr[i] = obj.arr[i];
    
    return *this;
}

template <class T>
T* Array<T>::getData() const
{
    return arr;
}

template <class T>
void Array<T>::insertAt(T val, int ind)
{
    if (ind<=size)
    {
        T* temp = new T[size+1];
        for (int i=0; i<ind; i++)
            temp[i] = arr[i];
        temp[ind] = val;
        for (int i=ind+1, j=ind; j<size; i++, j++)
            temp[i] = arr[j];
        delete [] arr;
        size++;
        arr = temp;
    }
    else
        cout << "index is out of range" << endl;
}

template <class T>
void Array<T>::removeAt(int ind)
{
    if (ind<size)
    {
        T* temp = new T[size-1];
        for (int i=0; i<ind; i++)
            temp[i] = arr[i];
        for (int i=ind, j=ind+1; j<size; i++, j++)
            temp[i] = arr[j];
        delete [] arr;
        size--;
        arr = temp;
    }
    else
        cout << "index is out of range" << endl;
}

int main()
{
    srand(time(NULL));
    Array<double> arr1(10);
    arr1.initRand();
    arr1.print();
    arr1.insertAt(225, 10);
    arr1.print();
    arr1.removeAt(5);
    arr1.print();
    
    return 0;
}
