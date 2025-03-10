#include "listHeader.hpp"

int main() {
    // 1. Create an empty list
    forwardList<int> list1;
    std::cout << "Created an empty list.\n";

    // 2. Insert elements using push_front
    list1.push_front(3);
    list1.push_front(2);
    list1.push_front(1);
    std::cout << "List after push_front(1), push_front(2), push_front(3): ";
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 3. Insert after a given node
    Iterator<int> it = list1.begin();
    list1.insert_after(it.data, 4); // Inserts 4 after 1
    std::cout << "List after insert_after(1, 4): ";
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 4. Erase after a given node
    list1.erase_after(it.data);  // Erases 4
    std::cout << "List after erase_after(1): ";
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 5. Emplace after a node
    list1.emplace_after(it, 99);
    std::cout << "List after emplace_after(1, 99): ";
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 6. Resize the list
    list1.resize(6, 7);  // Resizing to 6 elements, filling with 7
    std::cout << "List after resize(6, 7): ";
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 7. Create another list and merge
    forwardList<int> list2;
    list2.push_front(8);
    list2.push_front(5);
    list2.push_front(4);
    list1.merge(list2);
    std::cout << "List after merge with {4, 5, 8}: ";
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 8. Splice after
    forwardList<int> list3;
    list3.push_front(20);
    list3.push_front(10);
    list1.splice_after(it, list3);
    std::cout << "List after splice_after (moving {10, 20} after 1): ";
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 9. Swap two lists
    forwardList<int> list4;
    list4.push_front(50);
    list4.push_front(40);
    list4.push_front(30);
    list1.swap(list4);
    std::cout << "List1 after swap with list4 {30, 40, 50}: ";
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "List4 after swap (original list1 content): ";
    for (auto it = list4.begin(); it != list4.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}