#pragma once

namespace s21
{
    template <class T> class container;

    template <class T> class sequence_container;
    template <class T> class vector;
    template <class T> class deque;
    template <class T> class list;

    template <class T> class set_container;
    template <class T> class set;
    template <class T> class multiset;
    
    template <class T1, class T2> class associative_container;
    template <class T1, class T2> class map;
    template <class T1, class T2> class multimap;

    template <class T> class container_adapter;
    template <class T, container<T>> class stack;
    template <class T, container<T>> class queue;
    template <class T, container<T>> class priority_queue;

    template <class T1, class T2> class pair;
    class thing;
    class object;
    class primitive_element;
    template <class T> class pointer;
}

template<class T>
class s21::container{};

template<class T>
class s21::container_adapter
{
    container<T> *cont;
};

class s21::thing {};

class s21::object : public s21::thing {};
class s21::primitive_element : public s21::thing {};
template<class T> class s21::pointer : public s21::thing {};