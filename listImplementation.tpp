#include "listHeader.hpp"

// -----------------------------------------------------------
// Node Constructor (Copy) - Initializes the node with given data 
// and sets its next pointer to nullptr, making it the last node in a list.
// -----------------------------------------------------------
template <typename T>
Node<T>::Node(const T& data) : m_data(data), m_next(nullptr) { }


// -----------------------------------------------------------
// Node Constructor (Move) - Moves the given rvalue data into 
// the node and sets its next pointer to nullptr. Efficient for 
// transferring ownership of resources without copying.
// -----------------------------------------------------------
template <typename T>
Node<T>::Node(T&& data) : m_data(std::move(data)), m_next(nullptr) { }


// -----------------------------------------------------------
// Node Constructor (Perfect Forwarding) - Perfectly forwards
// the constructor arguments to initialize the node's data, 
// creating a node with variable arguments and setting its 
// next pointer to nullptr.
// -----------------------------------------------------------
template <typename T>
template<typename... Args>
Node<T>::Node(Args&&... args) : m_data(std::forward<Args>(args)...), m_next(nullptr) { }


// -----------------------------------------------------------
// forwardList Constructor (Default) - Initializes an empty
// forwardList with a null head pointer, representing an empty list.
// -----------------------------------------------------------
template <typename T>
forwardList<T>::forwardList() : m_head(nullptr) { }


// -----------------------------------------------------------
// forwardList Constructor (Count and Value) - Creates a forwardList
// of a specific count, where each node is initialized with the same value.
// It links the nodes together, forming a list of the given size.
// -----------------------------------------------------------
template <typename T>
forwardList<T>::forwardList(size_type count, const T& value) {
    m_head = nullptr;
    Node<T>** current = &m_head;

    for (size_type i = 0; i < count; ++i) {
        *current = new Node<T>(value);
        current = &(*current)->m_next;
    }
}


// -----------------------------------------------------------
// forwardList Constructor (Count) - Initializes a forwardList
// with the specified count, and the nodes are initialized with
// a default constructed value (T()).
// -----------------------------------------------------------
template <typename T>
forwardList<T>::forwardList(size_type count) : forwardList(count, T()) { }


// -----------------------------------------------------------
// Destructor - Deallocates memory by traversing the list and
// deleting each node. Ensures no memory leak when the list is destroyed.
// -----------------------------------------------------------
template <typename T>
forwardList<T>::~forwardList() {
    while (m_head) {
        Node<T>* temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
}


// -----------------------------------------------------------
// forwardList Constructor (Copy) - Creates a copy of the provided
// forwardList. It allocates new memory for each node and copies over the data.
// -----------------------------------------------------------
template <typename T>
forwardList<T>::forwardList(const forwardList<T>& other) : m_head(nullptr) {
    if (other.m_head) {
        m_head = new Node<T>(other.m_head->m_data);
        Node<T>* current1 = m_head;
        Node<T>* current2 = other.m_head->m_next;

        while (current2) {
            current1->m_next = new Node<T>(current2->m_data);
            current1 = current1->m_next;  
            current2 = current2->m_next;
        }
    }
}


// -----------------------------------------------------------
// Assignment Operator - Performs a deep copy of the other
// forwardList. It first clears the current list, then allocates
// new nodes and copies the data from the other list.
// -----------------------------------------------------------
template <typename T>
forwardList<T>& forwardList<T>::operator=(const forwardList<T>& other) {
    if (this != &other) {  
        while (m_head) {
            Node<T>* tmp = m_head;
            m_head = m_head->m_next;
            delete tmp;
        }
        if (other.m_head) {
            m_head = new Node<T>(other.m_head->m_data);
            Node<T>* current1 = m_head;
            Node<T>* current2 = other.m_head->m_next;

            while (current2) {
                current1->m_next = new Node<T>(current2->m_data);
                current1 = current1->m_next;  
                current2 = current2->m_next;
            }
        }
    }
    return *this;
}


// -----------------------------------------------------------
// insert_after - Inserts a new node with the given data after
// the specified node. Throws an exception if the node is null.
// -----------------------------------------------------------
template <typename T>
void forwardList<T>::insert_after(Node<T>* node, T data) {
    if (!node) {
        throw std::invalid_argument("Cannot insert after a null node");
    }
    Node<T>* new_node = new Node<T>(data);
    new_node->m_next = node->m_next;
    node->m_next = new_node;
}


// -----------------------------------------------------------
// emplace_after - Emplaces a new node after the specified position
// in the list. It forwards the arguments to construct the new node
// in place, avoiding unnecessary copies.
// -----------------------------------------------------------
template <typename T>
template  <typename... Args>
typename forwardList<T>::iterator forwardList<T>::emplace_after(typename forwardList<T>::iterator pos, Args&&... args) {
    Node<T>* newNode = new Node<T>(std::forward<Args>(args)...);
    newNode->m_next = pos.data->m_next;
    pos.data->m_next = newNode;
    return iterator(newNode);
}


// -----------------------------------------------------------
// insert_range_after - Inserts a range of nodes after the specified
// position in the list. The range is provided by two input iterators.
// -----------------------------------------------------------
template <typename T>
template <typename InputIt>
typename forwardList<T>::iterator forwardList<T>::insert_range_after(typename forwardList<T>::const_iterator pos, InputIt first, InputIt last) {
    Node<T>* current = pos.data;
    Node<T>* newNode = nullptr;
    while (first != last) {
        newNode = new Node<T>(*first);
        newNode->m_next = current->m_next;
        current->m_next = newNode;
        current = newNode;
        ++first;
    }
    return iterator(newNode);
}


// -----------------------------------------------------------
// erase_after - Deletes the node following the given node.
// Throws an exception if the provided node is null.
// -----------------------------------------------------------
template <typename T>
void forwardList<T>::erase_after(Node<T>* node) {
    if (!node) {
        throw std::invalid_argument("Cannot erase after a null node");
    }
    delete node->m_next;
    node->m_next = node->m_next->m_next;
}


// -----------------------------------------------------------
// push_front - Adds a new node with the provided data at the front
// of the list. The new node points to the current head of the list.
// -----------------------------------------------------------
template <typename T>
void forwardList<T>::push_front(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->m_next = m_head;
    m_head = newNode;
}


// -----------------------------------------------------------
// emplace_front - Emplaces a new node with the provided arguments
// at the front of the list. The node is constructed in place, 
// avoiding any unnecessary copies.
// -----------------------------------------------------------
template <typename T>
template <typename... Args>
void forwardList<T>::emplace_front(Args&&... args) {
    Node<T>* newNode = new Node<T>(std::forward<Args>(args)...);
    newNode->m_next = m_head;
    m_head = newNode;
}


// -----------------------------------------------------------
// prepend_range - Adds a range of nodes at the front of the list.
// The range is provided by two input iterators.
// -----------------------------------------------------------
template <typename T>
template <typename InputIt>
typename forwardList<T>::iterator forwardList<T>::prepend_range(InputIt first, InputIt last) {
    Node<T>* newHead = nullptr;
    Node<T>* tail = nullptr;

    for (auto it = first; it != last; ++it) {
        Node<T>* newNode = new Node<T>(*it);
        if (!newHead) {
            newHead = newNode;
            tail = newNode;
        }
        else {
            newNode->m_next = newHead;
            newHead = newNode;
        }
    }
    if (tail) {
        tail->m_next = m_head;
        m_head  = newHead;
    }
}


// -----------------------------------------------------------
// resize - Resizes the list to the given count. If the list is too long,
// it truncates the extra nodes. If the list is too short, it appends new 
// nodes with the specified value to the end of the list.
// -----------------------------------------------------------
template <typename T>
void forwardList<T>::resize(size_type count, const T& value) {
    Node<T>* current = m_head;
    typename forwardList<T>::size_type size = 0;

    while (current && size < count) {
        current = current->m_next;
        ++size;
    }

    if (size == count) {
        Node<T>* tmp = current->m_next;
        current->m_next = nullptr;
        while (tmp) {
            Node<T>* next = tmp->m_next;
            delete tmp;
            tmp = next;
        }
    } 
    else {
        Node<T>* last = current ? current : m_head;
        while (size < count) {
            Node<T>* newNode = new Node<T>(value);
            if (last) {
                last->m_next = newNode;
            }
            else {
                m_head = newNode;
            }
            last = newNode;
            ++size;
        }
    }
}


// -----------------------------------------------------------
// swap - Swaps the contents of this list with another list.
// The head pointers are swapped, and the internal structures
// of both lists are exchanged.
// -----------------------------------------------------------
template <typename T>
void forwardList<T>::swap(forwardList<T>& other) {
    std::swap(m_head, other.m_head);
}


// -----------------------------------------------------------
// merge - Merges another forwardList into the current list.
// If the current list is empty, the list is directly initialized 
// with the elements from the other list. If not, the elements from
// the other list are appended to the end of the current list.
// -----------------------------------------------------------
template <typename T>
void forwardList<T>::merge(const forwardList& other) {
    // If the other list is empty, there's nothing to merge
    if (!other.m_head) {
        return;
    }
    
    // If the current list is empty, copy the entire other list to it
    if (!m_head) {
        m_head = new Node<T>(other.m_head->m_data);
        Node<T>* current1 = m_head;
        Node<T>* current2 = other.m_head->m_next;

        // Traverse through the other list and copy its elements
        while (current2) {
            current1->m_next = new Node<T>(current2->m_data);
            current1 = current1->m_next;
            current2 = current2->m_next;
        }
        return;
    }
    
    // If the current list is not empty, traverse to the end
    Node<T>* current1 = m_head;
    while (current1->m_next) {
        current1 = current1->m_next;
    }
    
    // Append elements from the other list to the end of the current list
    Node<T>* current2 = other.m_head;
    while (current2) {
        current1->m_next = new Node<T>(current2->m_data);
        current2 = current2->m_next;
        current1 = current1->m_next;
    }
}


// -----------------------------------------------------------
// splice_after - Splices (inserts) the entire other forwardList 
// after the specified iterator position in the current list.
// After splicing, the other list becomes empty, and its elements
// are merged into the current list.
// -----------------------------------------------------------
template <typename T>
void forwardList<T>::splice_after(typename forwardList<T>::iterator pos, forwardList<T>& other) {
    // If the other list is empty, there's nothing to splice
    if (!other.m_head) {
        return;
    }
    
    Node<T>* current1 = pos.data;
    Node<T>* current2 = other.m_head;
    
    // If the specified position is valid, link the elements from the other list
    if (current1) {
        Node<T>* temp = current1->m_next;
        current1->m_next = current2;

        // Traverse to the end of the other list and link it back
        while (current2->m_next) {
            current2 = current2->m_next;
        }
        current2->m_next = temp;
    }
    // If the specified position is null (beginning of the list), just move the head
    else {
        m_head = other.m_head;
    }

    // After the operation, the other list is empty
    other.m_head = nullptr;
}


// -----------------------------------------------------------
// begin - Returns an iterator pointing to the first element in
// the list. Useful for traversing or modifying the list from 
// the start.
// -----------------------------------------------------------
template <typename T>
typename forwardList<T>::iterator forwardList<T>::begin() {
    return typename forwardList<T>::iterator(m_head);
}


// -----------------------------------------------------------
// end - Returns an iterator pointing past the last element of
// the list. This iterator marks the boundary after the last element,
// helping to know where the list ends.
// -----------------------------------------------------------
template <typename T>
typename forwardList<T>::iterator forwardList<T>::end() {
    return typename forwardList<T>::iterator(nullptr);
}


// -----------------------------------------------------------
// cbegin - Returns a constant iterator pointing to the first 
// element of the list. The constant iterator prevents modification
// of the list while traversing it.
// -----------------------------------------------------------
template <typename T>
typename forwardList<T>::const_iterator forwardList<T>::cbegin() const {
    return typename forwardList<T>::const_iterator(m_head);
}


// -----------------------------------------------------------
// cend - Returns a constant iterator pointing past the last 
// element of the list. This constant iterator ensures the list 
// cannot be modified during iteration.
// -----------------------------------------------------------
template <typename T>
typename forwardList<T>::const_iterator forwardList<T>::cend() const {
    return typename forwardList<T>::const_iterator(nullptr);
}


// -----------------------------------------------------------
// empty - Checks if the list is empty. It returns true if the list
// is empty (i.e., both begin and end iterators are the same),
// otherwise, it returns false indicating that the list contains elements.
// -----------------------------------------------------------
template <typename T>
bool forwardList<T>::empty() const {
    return this->begin() == this->end();
}
