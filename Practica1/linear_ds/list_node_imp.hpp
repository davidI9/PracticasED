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
#include <list_node.hpp>

template <class T>
bool ListNode<T>::is_dummy() const
{
    // TODO: recode with respect to your representation.
    return(_item==nullptr);
    //
}

template <class T>
ListNode<T>::ListNode()
{
    // TODO
    This_=nullptr;
    _next=nullptr;
    _prev=nullptr;
    _item=nullptr;
    //
    assert(is_dummy());
}

template <class T>
ListNode<T>::ListNode(T const &it)
{
    // TODO
    _item=std::shared_ptr<T>(new T(it));
    _prev=nullptr;
    _next=nullptr;
    //
    assert(!is_dummy());
    assert(next() == nullptr);
    assert(prev() == nullptr);
}

template <class T>
ListNode<T>::ListNode(T const &it, Ref next_n)
{
    // TODO
    _item=std::shared_ptr<T>(new T(it));
    _prev=nullptr;
    _next=next_n;
    //
    assert(!is_dummy());
    assert(next() == next_n);
    assert(prev() == nullptr);
}

template <class T>
ListNode<T>::ListNode(T const &it, Ref next_n, Ref prev_n)
{
    // TODO
    _item=std::shared_ptr<T>(new T(it));
    _prev=prev_n;
    _next=next_n;
    //
    assert(!is_dummy());
    assert(next() == next_n);
    assert(prev() == prev_n);
}

template <class T>
typename ListNode<T>::Ref ListNode<T>::create()
{
    auto ret_v = std::shared_ptr<ListNode<T>>(new ListNode<T>());
    ret_v->This_ = ret_v;
    assert(ret_v == ret_v->This());
    return ret_v;
}

template <class T>
typename ListNode<T>::Ref ListNode<T>::create(T const &it)
{
    auto ret_v = std::shared_ptr<ListNode<T>>(new ListNode<T>(it));
    ret_v->This_ = ret_v;
    assert(ret_v == ret_v->This());
    return ret_v;
}

template <class T>
typename ListNode<T>::Ref ListNode<T>::create(T const &it, Ref const &next_n)
{
    auto ret_v = std::shared_ptr<ListNode<T>>(new ListNode<T>(it, next_n));
    ret_v->This_ = ret_v;
    assert(ret_v == ret_v->This());
    return ret_v;
}

template <class T>
typename ListNode<T>::Ref ListNode<T>::create(T const &it, Ref const &next_n, Ref const &prev_n)
{
    auto ret_v = std::shared_ptr<ListNode<T>>(new ListNode<T>(it, next_n, prev_n));
    ret_v->This_ = ret_v;
    assert(ret_v == ret_v->This());
    return ret_v;
}

template <class T>
typename ListNode<T>::Ref ListNode<T>::This()
{
    return This_;
}

template <class T>
T const &ListNode<T>::item() const
{
    assert(!is_dummy());

    // TODO: recode with respect to your representation.
    return *_item;
    //
}

template <class T>
typename ListNode<T>::Ref ListNode<T>::prev() const
{
    // TODO: recode with respect to your representation.
    return _prev;
    //
}

template <class T>
typename ListNode<T>::Ref ListNode<T>::next() const
{
    // TODO: recode with respect to your representation.
    return _next;
    //
}

template <class T>
void ListNode<T>::set_item(const T &new_it)
{
    // TODO
    _item=std::shared_ptr<T>(new T(new_it));
    //
}

template <class T>
void ListNode<T>::set_prev(ListNode<T>::Ref n)
{
    // TODO
    _prev=n;
    //
    assert(n == prev());
}

template <class T>
void ListNode<T>::set_next(ListNode<T>::Ref n)
{
    // TODO
    _next=n;
    //
    assert(n == next());
}
