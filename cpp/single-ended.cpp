#include <iostream>

template <typename T>
struct ListNode {
    T data;
    ListNode* next;
};

template <typename T>
struct LinkedList {
    ListNode<T> *head;
    int size;
    LinkedList<T>() {
        head = nullptr;
        size = 0;
    }
    void insert(T data, int index);
    void remove(int index);
};

template <typename T>
void LinkedList<T>::insert(T data, int index) {
    ListNode<T> *node = new ListNode<T>;
    node->data = data;
    node->next = nullptr;
    
    if (index == 0) {
        node->next = head;
        head = node;
        return;
    }

    ListNode<T> *current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
    size++;
}

template <typename T>
void LinkedList<T>::remove(int index) {
    if (index == 0) {
        ListNode<T> *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode<T> *current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    ListNode<T> *temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}


int main(void) {

    LinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(6, 2); // to be removed
    list.insert(3, 3);
    list.insert(4, 4);

    list.remove(2);

    ListNode<int> *current = list.head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }

    current = list.head;
    while (current != nullptr) {
        ListNode<int> *next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}
