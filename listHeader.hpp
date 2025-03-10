#ifndef LIST_H
#define LIST_H

#include "listIteratorHeader.hpp"

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
};

template <typename T, typename Allocator = std::allocator<T> >
class forwardList {
public:
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using refermce = value_type&;
    using const_refernce = const value_type&;
    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T>;

public:
    forwardList();
    explicit forwardList(const Allocator&);
    forwardList(size_type, const T&, const Allocator&);
    explicit forwardList(size_type);
    ~Forward_list();
    Forward_list(const Forward_list&);
    Forward_list& operator=(const Forward_list&);
    void insert_after(Node<T>*, T);

    template  <typename... Args>
    iterator emplace_after(const_iterator, Args&&...);

    iterator insert_range_after(const_iterator, InputIt, InputIt);
    void erase_after(Node<T>*);
    void push_front(T);

    template <typename... Args>
    void emplace_front(Args&&...);

    template <typename InputIt>
    iterator prepend_range(InputIt, InputIt);

    void resize(size_type, const T&);
    void swap(Forward_list&);
    void merge(const Forward_list&);
    void splice_after(const_iterator, Forward_list<T>&);
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

private:
    Node<T>* m_head;
    allocator_type m_allocator;
};

#include "listImplementation.tpp"

#endif