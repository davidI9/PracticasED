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
#include <cassert>
#include <cdarray.hpp>

template <class T>
size_t 
CDArray<T>::capacity() const
{
    // TODO: recode with respect to your representation.
    return capacity_;
    //
}

template <class T>
size_t
CDArray<T>::size() const
{
    // TODO: recode with respect to your representation.
    return size_;
    //
}

template <class T>
bool CDArray<T>::is_empty() const
{
    // TODO: recode with respect to your representation.
    return (size_==0);
    //
}

template <class T>
bool CDArray<T>::is_full() const
{
    bool ret_v = false;
    // TODO
    if(size_ == capacity_){
        ret_v = true;
    }
    //
    assert(!ret_v || size() == capacity());
    return ret_v;
}

template <class T>
CDArray<T>::CDArray(size_t cap)
{
    assert(cap > 0);
    // TODO
    capacity_=cap;
    size_=0;
    front_=0;
    back_=0;
    data_ = std::shared_ptr<T[]>(new T[cap]);
    //
    assert(capacity() == cap);
    assert(is_empty());
    assert(size() == 0);
}

template <class T>
CDArray<T>::CDArray() : CDArray(1) {}

template <class T>
T const &CDArray<T>::get(size_t pos) const
{
    // TODO: recode with respect to your representation.
    size_t real = (front_+pos)%capacity_;
    return(data_[real]);
    //
}

template <class T>
T const &CDArray<T>::front() const
{
    assert(!is_empty());
    // TODO: recode with respect to your representation.
    return data_[front_]; // fixme
    //
}

template <class T>
T const &CDArray<T>::back() const
{
    assert(!is_empty());
    // TODO: recode with respect to your representation.
    return data_[back_]; // fixme
    //
}

template <class T>
void CDArray<T>::set(size_t pos, T const &new_v)
{
    // TODO
    data_[(front_+pos)%capacity_]=new_v;
    //
    assert(new_v == get(pos));
}

template <class T>
void CDArray<T>::set_front(T const &new_v)
{
    assert(!is_empty());
    // TODO
    data_[front_]=new_v;
    //
    assert(new_v == front());
}

template <class T>
void CDArray<T>::set_back(T const &new_v)
{
    assert(!is_empty());
    // TODO
    data_[back_]=new_v;
    //
    assert(new_v == back());
}

inline size_t cInc(size_t v, size_t size)
{
    size_t ret_v;
    // TODO
    ret_v = (v+1)%size;
    //
    return ret_v;
}

inline size_t cDec(size_t v, size_t size)
{
#ifndef NDEBUG
    size_t old_v = v;
#endif
    size_t ret_v;
    // TODO
    // Remember: v is a unsigned value, so you must cast to signed before decrementing
    int sv = static_cast<int>(v);
    sv = (sv-1);
    if(sv<0){sv=size-1;};
    ret_v = sv%size;
    //
    assert(old_v == cInc(ret_v, size));
    return ret_v;
}

template <class T>
void CDArray<T>::push_front(T const &new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
    bool old_is_empty = is_empty();
    T old_front = is_empty() ? T() : get(0);
#endif
    // TODO
    if(this->is_full()){this->grow();}
    if(!(this->is_empty())){front_ = cDec(front_, capacity_);}
    else{
        front_=0;
        back_=0;
    }
    size_++;
    this->set_front(new_it);
    //
    assert(size() == old_size + 1);
    assert(get(0) == new_it);
    assert(old_is_empty || (get(1) == old_front));
}

template <class T>
void CDArray<T>::push_back(T const &new_it)
{
#ifndef NDEBUG
    size_t old_size = size();
    bool old_is_empty = is_empty();
    T old_back = is_empty() ? T() : get(size() - 1);
#endif
    // TODO
    if(this->is_full()){this->grow();}
    if(!(this->is_empty())){back_ = cInc(back_, capacity_);}
    else{
        front_=0;
        back_=0;
    }
    size_++;
    this->set_back(new_it);
    //
    assert(size() == old_size + 1);
    assert(get(size() - 1) == new_it);
    assert(old_is_empty || (get(size() - 2) == old_back));
}

template <class T>
void CDArray<T>::pop_front()
{
#ifndef NDEBUG
    size_t old_size = size();
    T old_next_front = size() > 1 ? get(1) : T();
#endif
    // TODO
    front_ = cInc(front_, capacity_);
    size_--;
    //
    assert(size() == old_size - 1);
    assert(is_empty() || get(0) == old_next_front);
}

template <class T>
void CDArray<T>::pop_back()
{
#ifndef NDEBUG
    size_t old_size = size();
    T old_prev_back = size() > 1 ? get(size() - 2) : T();
#endif
    // TODO
    back_ = cDec(back_, capacity_);
    size_--;
    //
    assert(size() == old_size - 1);
    assert(is_empty() || get(size() - 1) == old_prev_back);
}

template <class T>
void CDArray<T>::insert(size_t pos, T const &v)
{
    assert(pos >= 0 && pos < size());
#ifndef NDEBUG
    size_t old_size = size();
    T old_back = get(size() - 1);
    T old_pos_v = get(pos);
#endif
    // TODO
    // Hint: if pos==0, delegate in push_front.
    // Remember: back_ needs to be updated too.

    if(this->is_full()){
        this->grow();
    }
    
    if(pos == 0){
        this->push_front(v); 
    }
    
    else{
        size_++;
        back_ = cInc(back_, capacity_);
        
        for(size_t i = size_ - 1; i > pos; i--){
            this->set(i, this->get(i - 1));
        }

        this->set(pos, v);
    }
    //
    assert(size() == old_size + 1);
    assert(get(pos) == v);
    assert(get(pos + 1) == old_pos_v);
    assert(get(size() - 1) == old_back);
}

template <class T>
void CDArray<T>::remove(size_t pos)
{
    assert(pos >= 0 && pos < size());
#ifndef NDEBUG
    size_t old_size = size();
    T old_next_pos_v = (pos <= (size() - 2)) ? get(pos + 1) : T();
#endif
    // TODO
    // Remember: back_ needs to be updated.
    
    if(pos == size_-1){
        this->pop_back(); 
    }
    else if(pos==0){
        this->pop_front();
    }
    else{
        back_ = cDec(back_, capacity_);
        
        for(size_t i = pos; i < size_-1; i++){
            this->set(i, this->get(i+1));
        }

        size_--;
    }
    //
    assert(size() == old_size - 1);
    assert(pos == size() || get(pos) == old_next_pos_v);
}

template <class T>
void CDArray<T>::grow()
{
#ifndef NDEBUG
    size_t old_capacity = capacity();
    T old_front = get(0);
    T old_back = get(size() - 1);
#endif
    // TODO
    std::shared_ptr<T[]> newdata = std::shared_ptr<T[]>(new T[capacity_*2]);
    for(size_t i=0; i<size_; i++){
        newdata[i] = data_[(front_+i)%capacity_];
    }
    data_=newdata;
    back_=size_-1;
    front_=0;
    capacity_=capacity_*2;
    //
    assert(capacity() == 2 * old_capacity);
    assert(get(0) == old_front);
    assert(get(size() - 1) == old_back);
}

template <class T>
std::istream &
operator>>(std::istream &input, CDArray<T> &cdarray) noexcept(false)
{
    std::string token;
    // TODO
    // Hint: use std::istringstream to convert from "string" to template
    //  parameter T type.
    // Remember: throw std::runtime_error("Wrong input format.") exception when an input
    //  format error was found.
    
    T aux2;

    input >> token;
    if(token=="[]"){
        return input;
    }
    if(token != "["){
        throw std::runtime_error("Wrong input format.");
    }

    while(input >> token){
        if(token == "]"){
            break;
        }

        std::istringstream iss(token);
        if(!(iss >> aux2)){
            throw std::runtime_error("Wrong input format.");
        }
        
        cdarray.push_back(aux2);
    }
    //
    return input;
}

template <class T>
std::ostream &
operator<<(std::ostream &out, const CDArray<T> &cdarray)
{
    // TODO
    if(cdarray.is_empty()){
        out<<"[]";
    }else{
        out<<"[ ";
        for(size_t i=0; i<cdarray.size(); i++){
            out<<cdarray.get(i)<<" ";
        }
        out<<"]";
    }
    //
    return out;
}
