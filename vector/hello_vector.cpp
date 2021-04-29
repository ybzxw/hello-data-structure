#include <assert.h>
#include<stdlib.h>
#include "hello_vector.h"

template <typename T>
void Vector<T>::copy_from(T const* A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while(lo < hi)
        _elem[_size++] = A[lo++];
    
}

template <typename T>
Vector<T> & Vector<T>::operator=(Vector<T> const& V)
{
    if(_elem) delete [] _elem;
    copy_from(V._elem, 0, V.size());
    return *this;
}

template <typename T>
void Vector<T>::expand()
{
    if (_size < _capacity) return;
    if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T* old_elem = _elem;
    _elem = new T[_capacity <<= 1];
    for(int i = 0; i < _size; ++i)
        _elem[i] = old_elem[i];
    delete [] old_elem;
    return;
}

template <typename T>
void Vector<T>::shrink()
{
    if(_capacity < DEFAULT_CAPACITY << 1) return;
    if(_size << 2 > _capacity) return;
    T* old_elem = _elem;
    _elem = new T[_capacity >>= 1];
    for(int i = 0; i < _size; ++i)
        _elem[i] = old_elem[i];
    delete [] old_elem;
    return;
}

template <typename T>
T& Vector<T>::operator [] (Rank r) const
{
    assert(r >= 0 && r < _size);
    return _elem[r];
}

template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
    T* V = _elem + lo;
    for (Rank i = hi - ho; i > 0; --i)
        swap(V[i-1], V[rand() % i]);
}