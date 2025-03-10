#include "listIteratorHeader.hpp"

/**
 * @brief Default constructor for Iterator class.
 * 
 * Initializes the iterator with a null pointer. The iterator will point to no node.
 */
template <typename T>
Iterator<T>::Iterator() : data(nullptr) { }

/**
 * @brief Constructor for Iterator class that initializes the iterator with a given node.
 * 
 * @param p A pointer to a Node<T> object which the iterator will point to.
 */
template <typename T>
Iterator<T>::Iterator(Node<T>* p) : data(p) { }

/**
 * @brief Dereference operator to access the value of the current node the iterator is pointing to.
 * 
 * Returns a reference to the data of the node that the iterator is pointing to.
 * 
 * @return reference A reference to the data stored in the node.
 */
template <typename T>
typename Iterator<T>::reference Iterator<T>::operator*() const {
    return data->m_data; 
}

/**
 * @brief Arrow operator to access the value of the current node the iterator is pointing to.
 * 
 * Returns a pointer to the data of the node that the iterator is pointing to.
 * 
 * @return pointer A pointer to the data stored in the node.
 */
template <typename T>
typename Iterator<T>::pointer Iterator<T>::operator->() const {
    return &(data->m_data);  
}

/**
 * @brief Pre-increment operator to move the iterator forward.
 * 
 * Advances the iterator to the next node and returns the updated iterator.
 * 
 * @return Iterator<T>& A reference to the current iterator, after advancing.
 */
template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    if (data) {
        data = data->m_next;  // Move to the next node.
    }
    return *this;
}

/**
 * @brief Post-increment operator to move the iterator forward.
 * 
 * Creates a temporary copy of the iterator, advances the original iterator, and returns the temporary copy.
 * 
 * @param int Placeholder for the post-increment syntax.
 * @return Iterator<T> A copy of the iterator before it was incremented.
 */
template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator<T> tmp = *this;
    if (data) {
        data = data->m_next;  // Move to the next node.
    }
    return tmp;
}

/**
 * @brief Adds a given number of steps to the iterator.
 * 
 * Creates a new iterator and advances it `n` steps from the current position.
 * 
 * @param n The number of steps to move forward.
 * @return Iterator<T> A new iterator that is `n` steps ahead of the current one.
 */
template <typename T>
Iterator<T> Iterator<T>::operator+(difference_type n) const {
    Iterator<T> temp = *this;
    while (n-- && temp.data) {
        ++temp;  // Move to the next node.
    }
    return temp;
}

/**
 * @brief Adds a given number of steps to the current iterator.
 * 
 * Advances the current iterator `n` steps forward.
 * 
 * @param n The number of steps to move forward.
 * @return Iterator<T>& A reference to the current iterator, after advancing.
 */
template <typename T>
Iterator<T>& Iterator<T>::operator+=(difference_type n) {
    while (n-- && data) {
        ++(*this);  // Move to the next node.
    }
    return *this;
}

/**
 * @brief Equality comparison operator for iterators.
 * 
 * Compares if two iterators point to the same node.
 * 
 * @param other The iterator to compare with the current one.
 * @return bool True if both iterators point to the same node, otherwise false.
 */
template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const {
    return data == other.data;
}

/**
 * @brief Inequality comparison operator for iterators.
 * 
 * Compares if two iterators point to different nodes.
 * 
 * @param other The iterator to compare with the current one.
 * @return bool True if both iterators point to different nodes, otherwise false.
 */
template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const {
    return data != other.data;
}
