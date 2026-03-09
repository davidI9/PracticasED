/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once
#include <cassert>
#include <list_iterator.hpp>

template <class T>
bool ListIterator<T>::is_valid() const
{

    // TODO: recode with respect to your representation.

    return (_it!=nullptr);
    //
}

template <class T>
ListIterator<T>::ListIterator()
{
    // TODO
    _it = nullptr;
    //
    assert(!is_valid());
};

template <class T>
ListIterator<T>::ListIterator(typename ListNode<T>::Ref const &n)
{
    // TODO
    _it = n;
    //
    assert(n == nullptr || is_valid());
    assert(n != nullptr || !is_valid());
};

template <class T>
T const &ListIterator<T>::item() const
{
    assert(is_valid());
    // TODO: recode with respect to your representation.
    return _it->item();
    //
}

template <class T>
ListIterator<T> ListIterator<T>::next(size_t dist) const
{
    assert(is_valid());
    ListIterator<T> ret_v;
    // TODO
    ret_v._it=this->_it;
    for(size_t i=0; i<dist; i++){
        ret_v._it=ret_v._it->next();
    }
    //
    return ret_v;
}

template <class T>
ListIterator<T> ListIterator<T>::prev(size_t dist) const
{
    assert(is_valid());
    ListIterator<T> ret_v;
    // TODO
    ret_v._it=this->_it;
    for(size_t i=0; i<dist; i++){
        ret_v._it=ret_v._it->prev();
    }
    //
    return ret_v;
}

template <class T>
size_t ListIterator<T>::distance(ListIterator<T> const &other) const
{
    assert(is_valid());
    assert(other.is_valid());
    size_t ret_v = 0;
    // TODO
    ListIterator<T> aux;
    aux = *this;
    while(aux._it != other._it){
        aux.goto_next();
        ret_v++;
    }
    //
    return ret_v;
}

template <class T>
bool ListIterator<T>::operator==(ListIterator<T> const &o) const
{
    // TODO: recode with respect to your representation.
    // Remember: two iterators are equal if both point to the same node.
    return (this->_it == o._it);
    //
}

template <class T>
bool ListIterator<T>::operator!=(ListIterator<T> const &o) const
{

    // TODO: recode with respect to your representation.
    // Remember: two iterators are equal if both point to the same node.
    return (this->_it != o._it);
    //
}

template <class T>
void ListIterator<T>::set_item(T const &it)
{
    assert(is_valid());
    // TODO
    this->_it->set_item(it);
    //
}

template <class T>
void ListIterator<T>::goto_next(size_t dist)
{
    assert(is_valid());
    // TODO
    this->_it = this->next(dist)._it;
    //
}

template <class T>
void ListIterator<T>::goto_prev(size_t dist)
{
    assert(is_valid());
    // TODO
    this->_it = this->prev(dist)._it;
    //
}

template <class T>
typename ListNode<T>::Ref ListIterator<T>::node() const
{

    // TODO: recode with respect to your representation.
    return _it;
    //
}

template <class T>
void ListIterator<T>::set_node(typename ListNode<T>::Ref const &n)
{
    // TODO
    _it=n;
    //
    assert(node() == n);
}