#ifndef LIST_H
#define LIST_H

#include "listIteratorHeader.hpp"

template <typename T>
class forwardList;

template <typename T>
class Node {
private:
    T m_data;
    Node* m_next;
public:
    Node(const T&);
    Node(T&& data);

    template<typename... Args>
    Node(Args&&...);
    friend class forwardList<T>;
    friend class Iterator<T>;
};

template <typename T>
class forwardList {
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using refermce = value_type&;
    using const_refernce = const value_type&;
    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T>;

public:
    forwardList();
    forwardList(size_type, const T&);
    explicit forwardList(size_type);
    ~forwardList();
    forwardList(const forwardList&);
    forwardList& operator=(const forwardList&);
    void insert_after(Node<T>*, T);

    template  <typename... Args>
    iterator emplace_after(iterator, Args&&...);

    template <typename InputIt>
    iterator insert_range_after(const_iterator, InputIt, InputIt);

    void erase_after(Node<T>*);
    void push_front(T);

    template <typename... Args>
    void emplace_front(Args&&...);

    template <typename InputIt>
    iterator prepend_range(InputIt, InputIt);

    void resize(size_type, const T& value = T());
    void swap(forwardList&);
    void merge(const forwardList&);
    void splice_after(iterator, forwardList&);
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
    bool empty() const;

private:
    Node<T>* m_head;
};

#include "listImplementation.tpp"

#endif