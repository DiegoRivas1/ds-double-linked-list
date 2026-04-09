#include "Node.h"

template<typename T>
Node<T>::Node(T data): data(data), next(nullptr), prev(nullptr) {}

template<typename T>
Node<T>::Node(T data, Node<T> *next, Node<T> *prev): data(data), next(next), prev(prev) {}

template<typename T>
Node<T>::~Node() = default;

template<typename T>
T Node<T>::getData() const {
    return this->data;
}

template<typename T>
void Node<T>::setData(T newData) {
    this->data = newData;
}

template<typename T>
Node<T>* Node<T>::getNext() const {
    return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T> *newNext) {
    this->next = newNext;
}

template<typename T>
Node<T>* Node<T>::getPrev() const {
    return this->prev;
}

template<typename T>
void Node<T>::setPrev(Node<T> *newPrev) {
    this->prev = newPrev;
}
