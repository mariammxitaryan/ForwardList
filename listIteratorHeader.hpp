#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <memory>
#include <initializer_list>

template <typename T>
class Node;

template <typename T>
class forwardList;

template <typename T>
class Iterator {
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    Iterator();
    explicit Iterator(Node<T>*);
    reference operator*() const;
    pointer operator->() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator&) const;
    bool operator!=(const Iterator&) const;
    Iterator operator+(difference_type) const;
    Iterator& operator+=(difference_type);

    friend class forwardList<T>;
    friend class Node<T>;
public: 
    Node<T>* data;
};

#include "listIteratorImplementation.tpp"

#endif