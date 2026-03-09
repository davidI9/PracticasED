/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once

#include <sstream>
#include <stdexcept>
#include <cassert>

#include <list.hpp>

template <class T> 
List<T>::List()
{
    // TODO
    // Remember: in an empty list, the dummy node is linked with itself.
    dummy_ = ListNode<T>::create();
    dummy_->set_next(dummy_);
    dummy_->set_prev(dummy_);
    size_=0;
    //
    assert(is_empty());
}

template <class T>
typename ListNode<T>::Ref List<T>::dummy() const
{
    // TODO: recode with respect to your representation.
    return dummy_;
    //
}

template <class T>
bool List<T>::is_empty() const
{
    // TODO: recode with respect to your representation.
    return size_==0;
    //
}

template <class T>
size_t List<T>::size() const
{
    // TODO: recode with respect to your representation.
    return size_;
    //
}

template <class T>
void List<T>::set_size(size_t new_size)
{
    // TODO
    size_=new_size;
    //
    assert(size() == new_size);
}

template <class T>
typename List<T>::iterator List<T>::begin() const
{

    // TODO: recode with respect to your representation.
    return ListIterator<T>(dummy_->next());
    //
}

template <class T>
typename List<T>::iterator List<T>::end() const
{
    // TODO: recode with respect to your representation.

    return ListIterator<T>(dummy_);
    //
}

template <class T>
T const &List<T>::front() const
{
    assert(!is_empty());

    // TODO: recode with respect to your representation.
    // Hint: use iterators.
    return begin().item();
    //
}

template <class T>
T const &List<T>::back() const
{
    assert(!is_empty());

    // TODO: recode with respect to your representation.
    // Hint: use iterators.
    return end().prev().item();
    //
}

template <class T>
void List<T>::hook(typename ListNode<T>::Ref n, typename ListNode<T>::Ref pos)
{
#ifndef NDEBUG
    auto old_size = size();
#endif
    // TODO
    // Remember updating the size.
    n->set_next(pos);
    n->set_prev(pos->prev());
    n->prev()->set_next(n);
    pos->set_prev(n);
    size_++;
    //
    assert(size() == old_size + 1);
}

template <class T>
void List<T>::unhook(typename ListNode<T>::Ref pos)
{
#ifndef NDEBUG
    auto old_size = size();
#endif
    // TODO
    // Remember updating the size.
    pos->prev()->set_next(pos->next());
    pos->next()->set_prev(pos->prev());
    size_--;
    //
    assert(size() == old_size - 1);
}

template <class T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator const &pos,
                                           T const &it)
{
#ifndef NDEBUG
    auto old_is_empty = is_empty();
    auto old_size = size();
    auto old_pos_prev = pos.prev();
#endif
    iterator ret_v;
    // TODO
    // Hint: delegate in hook.
    typename ListNode<T>::Ref newnode = ListNode<T>::create(it);
    ret_v = ListIterator<T>(newnode);
    hook(newnode, pos.node());
    //
    assert(!old_is_empty || (front() == it && back() == it));
    assert(old_is_empty || ret_v.next() == pos);
    assert(old_is_empty || old_pos_prev == ret_v.prev());
    assert(size() == (old_size + 1));
    return ret_v;
}

template <class T>
typename List<T>::iterator List<T>::remove(List<T>::iterator const &pos)
{
    assert(!is_empty());
#ifndef NDEBUG
    auto old_size = size();
    auto old_pos_next = pos.next();
    auto old_pos_prev = pos.prev();
#endif
    iterator ret_v;
    // TODO
    // Hint: delegate in unkook
    ret_v = ListIterator<T>(pos.next());
    unhook(pos.node());
    //
    assert(ret_v == old_pos_next);
    assert(ret_v.prev() == old_pos_prev);
    assert(size() == (old_size - 1));
    return ret_v;
}

template <class T>
void List<T>::push_front(T const &new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
#endif
    // TODO
    //  Hint: delegate in insert();
    insert(begin(), new_it);
    //
    assert(front() == new_it);
    assert(size() == (old_size + 1));
}

template <class T>
void List<T>::push_back(T const &new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
#endif
    // TODO
    //  Hint: delegate in insert();
    insert(end(), new_it);
    //
    assert(back() == new_it);
    assert(size() == (old_size + 1));
}

template <class T>
void List<T>::pop_front()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
#endif
    // TODO
    // Hint: delegate in remove.
    remove(begin());
    //
    assert(size() == (old_size - 1));
}

template <class T>
void List<T>::pop_back()
{
    assert(!is_empty());
#ifndef NDEBUG
    size_t old_size = size();
    auto old_end_prev_prev = end().prev().prev();
#endif
    // TODO
    // Hint: delegate in remove.
    remove(end().prev());
    //
    assert(is_empty() || end().prev() == old_end_prev_prev);
    assert(size() == (old_size - 1));
}

template <class T>
typename List<T>::iterator List<T>::find(T const &it, List<T>::iterator const &from) const
{
    iterator ret_v;
    // TODO
    ret_v = from;
    while (ret_v!=end()){
        if(ret_v.item()==it){
            break;
        }
        ret_v.goto_next();
    }
    //
    assert(ret_v == end() || ret_v.item() == it);
    return ret_v;
}

template <class T>
void List<T>::splice(iterator const &pos, List<T> &list2,
                     iterator const &first, iterator const &last)
{
#ifndef NDEBUG
    size_t old_size = size();
    size_t old_l2_size = list2.size();
    auto old_range_size = first.distance(last);
#endif
    // TODO
    // Hint: if the range [first, last) is empty, nothing must be done.
    if(first==last){return;}
    size_t cutsize = first.distance(last);

    auto f_node = first.node();
    auto l_node = last.node();
    auto block_last = l_node->prev();
    auto p_node = pos.node();
    auto p_prev = p_node->prev();
    auto origin_prev = f_node->prev();

    origin_prev->set_next(l_node);
    l_node->set_prev(origin_prev);

    p_prev->set_next(f_node);
    f_node->set_prev(p_prev);
    
    block_last->set_next(p_node);
    p_node->set_prev(block_last);

    size_ += cutsize;
    list2.set_size(list2.size() - cutsize);
    //
    assert(size() == (old_size + old_range_size));
    assert(list2.size() == (old_l2_size - old_range_size));
}

template <class T>
void List<T>::splice(iterator const &pos, List<T> &list2)
{
#ifndef NDEBUG
    size_t old_size = size();
    auto old_list2_size = list2.size();
#endif
    // TODO
    // Hint: Delegate in splice the list2 range [begin, end).
    splice(pos, list2, list2.begin(), list2.end());
    //
    assert(size() == (old_size + old_list2_size));
    assert(list2.size() == 0);
    assert(list2.is_empty());
}

template <class T>
void List<T>::splice(iterator const &pos, List<T> &list2, iterator const &i)
{
#ifndef NDEBUG
    size_t old_size = size();
    auto old_list2_size = list2.size();
#endif
    // TODO
    // Hint: Delegate in splice the list2 range [i, i.next()).
    splice(pos, list2, i, i.next());
    //
    assert(size() == (old_size + 1));
    assert(list2.size() == (old_list2_size - 1));
}

template <class T>
template <class Compare>
void List<T>::merge(List<T> &other, Compare comp)
{
    // TODO
    // Remember: The nodes of the other list are spliced into this list.
    auto it1 = begin();
    auto it2 = other.begin();

    while(it1!=end() && it2!=other.end()){
        if(!(comp(it1.item(), it2.item()))){
            auto aux = it2;
            aux.goto_next();

            splice(it1, other, it2);
            it2 = aux;
        }
        else{
            it1.goto_next();
        }
    }
    if (!other.is_empty()){
        splice(end(), other);
    }
    //
}

template <class T>
template <class Compare>
void List<T>::sort(Compare comp)
{
    // TODO
    // Remember: we want a complexity in to N Log(N) so mergeSort algorithm is
    // a good candidate to sort the list.
    // Hint: Do a recursive implementation, splitting the list into two halves,
    // sorting recursively each part and merging the sorted lists to obtain
    // the full sorted list.
    if (size() <= 1) {return;}

    List<T> other;
    auto middle = begin();
    for (size_t i = 0; i < size() / 2; ++i){
        middle.goto_next();
    }

    other.splice(other.begin(), *this, middle, end());

    sort(comp);
    other.sort(comp);

    merge(other, comp);
    //
}

template <class T>
std::ostream &
operator<<(std::ostream &out, List<T> const &list)
{
    // TODO
    if(list.is_empty()){
        out<<"[]";
    }
    else{
        out << "[ ";
        for (auto it = list.begin(); it != list.end(); )
        {
            out << it.item();
            it.goto_next();
            if (it != list.end()) out << " ";
        }
        out << " ]";
    }
    //
    return out;
}

template <class T>
std::istream &
operator>>(std::istream &in, List<T> &list)
{

    std::string token;
    // TODO
    // Hint: use std::istringstream to convert from a "string" token value to a template
    // T type value.
    // Remember: throw std::runtime_error("Wrong input format.") exception when an input
    //  format error was found.
    T aux2;

    in >> token;
    if(token=="[]" || token=="[ ]"){
        return in;
    }
    if(token != "["){
        throw std::runtime_error("Wrong input format.");
    }

    while(in >> token){
        if(token == "]"){
            break;
        }

        std::istringstream iss(token);
        if(!(iss >> aux2)){
            throw std::runtime_error("Wrong input format.");
        }
        
        list.push_back(aux2);
    }
    
    if(token!="]"){
        throw std::runtime_error("Wrong input format.");
    }

    //
    return in;
}
