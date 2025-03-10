```markdown
# **Forward List - A Custom Linked List Implementation in C++**

Welcome to **Forward List**! This project is a custom implementation of a **forward list** (a singly linked list) using C++ templates. It provides a set of powerful and efficient functions for list manipulation and can be used as a building block for more advanced data structures.

## 📚 **Table of Contents**
1. [Overview](#overview)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
    - [Creating a List](#creating-a-list)
    - [Adding Elements](#adding-elements)
    - [Merging Lists](#merging-lists)
    - [Splicing Lists](#splicing-lists)
    - [Iterating Through the List](#iterating-through-the-list)
    - [Checking if the List is Empty](#checking-if-the-list-is-empty)

---

## 🔍 **Overview**
`Forward List` is a C++ template class that implements a basic singly linked list. It supports a wide range of list operations such as merging, splicing, and iterating, providing a foundation for more complex data structures.

The project showcases how to:
- Use **C++ templates** to create a generic list
- Implement **iterators** for easy traversal
- Perform operations like **merge** and **splice** that are common in real-world applications

---

## 🚀 **Features**
- **Merge**: Merge another forward list into the current list.
- **Splice**: Insert elements from one list into another at a specified position.
- **Iterators**: Support for both regular and constant iterators to traverse and modify the list.
- **Empty Check**: Easily check if the list is empty.
- **Beautiful Design**: Clean and readable code with detailed comments for better understanding.

---

## 🛠️ **Installation**

To use **Forward List** in your project, follow these steps:

### Prerequisites
- A C++ compiler supporting C++11 or higher.
- Any C++ IDE or text editor (e.g., Visual Studio, CLion, or Sublime Text).

### Clone the Repository

```bash
git clone https://github.com/your-username/forward-list.git
```

### Build the Project

1. Navigate to the project directory:

```bash
cd forward-list
```

2. Compile the code using your preferred C++ compiler. For example, with **g++**:

```bash
g++ -std=c++20 -o forward-list main.cpp
```

3. Run the compiled executable:

```bash
./forward-list
```

---

## 📝 **Usage**

### **Creating a List**
You can create a forward list of any type (e.g., `int`, `string`) like this:

```cpp
forwardList<int> list;
```

### **Adding Elements**
Use `push_front()` to add an element to the front of the list:

```cpp
list.push_front(10);
list.push_front(20);
```

### **Merging Lists**
You can merge another list into the current list using the `merge()` function:

```cpp
forwardList<int> otherList;
otherList.push_front(30);
otherList.push_front(40);

list.merge(otherList);
```

### **Splicing Lists**
Use the `splice_after()` function to insert the elements of one list into another at a specified position:

```cpp
forwardList<int>::iterator it = list.begin();
list.splice_after(it, otherList);
```

### **Iterating Through the List**
You can use iterators to traverse the list:

```cpp
for (auto it = list.begin(); it != list.end(); ++it) {
    std::cout << *it << " ";
}
```

### **Checking if the List is Empty**
To check if the list is empty, use the `empty()` function:

```cpp
if (list.empty()) {
    std::cout << "The list is empty!" << std::endl;
} else {
    std::cout << "The list has elements." << std::endl;
}
```

---

**Thank you for checking out Forward List!**  
Happy coding! 💻✨
```
