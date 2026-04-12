#pragma once
#include <stdexcept>
#include <iostream>
#include <sstream>

template<typename T>
DoubleCircularList<T>::DoubleCircularList() : head(nullptr), tail(nullptr) , length(0) {}

template<typename T>
DoubleCircularList<T>::DoubleCircularList(const DoubleCircularList<T> &other) : head(nullptr), tail(nullptr), length(0) {
    *this = other;
}

template<typename T>
template<typename U>
DoubleCircularList<T>::DoubleCircularList(const DoubleCircularList<U> &other) : head(nullptr), tail(nullptr), length(0) {
    *this = other;
}

template<typename T>
DoubleCircularList<T>::~DoubleCircularList() {
    this ->DoubleCircularList<T>::clear();
}

template<typename T>
void DoubleCircularList<T>::insert(T data, int position) {
    if (position < 0 || position > length) {
        throw std::out_of_range("Posicion invalida");
    }
    auto* newNode = new Node<T>(data);//Node<T>* newNode = new Node<T>(data);

    // Lista vacia O(1)
    if (isEmpty()) {
        this -> head = newNode;
        this -> tail = newNode;
        newNode->setNext(newNode); // apunta a si mismo
        newNode->setPrev(newNode);
    }
    // Inicio O(1)
    else if (position == 0) {
        newNode->setNext(this -> head);
        newNode->setPrev(this -> tail);
        this -> head->setPrev(newNode);
        this -> tail->setNext(newNode);
        this -> head = newNode;
    }
    // Final O(1)
    else if (position == this -> length) {
        newNode->setNext(this -> head);
        newNode->setPrev(this -> tail);
        this -> tail->setNext(newNode);
        this -> head->setPrev(newNode);
        this -> tail = newNode;
    }
    // Medio O(n)
    else {
        Node<T>* current = this->searchNode(position - 1);
        newNode->setNext(current->getNext());
        newNode->setPrev(current);
        current->getNext()->setPrev(newNode);
        current->setNext(newNode);
    }
    ++this -> length;

}

template<typename T>
void DoubleCircularList<T>::remove(int position) {
    if (position < 0 || position >= length) {
        throw std::out_of_range("Posicion invalida");
    }
    Node<T>* toDelete;

    // 1 elemento O(1)
    if (this -> length == 1) {
        toDelete = this -> head;
        this -> head = nullptr;
        this -> tail = nullptr;
    }
    // Inicio O(1)
    else if (position == 0) {
        toDelete = this -> head;
        this -> head = this -> head->getNext();
        this -> head->setPrev(this -> tail);
        this -> tail->setNext(this -> head);
    }
    // Final O(1)
    else if (position == this -> length - 1) {
        toDelete = this -> tail;
        this -> tail = this -> tail->getPrev();
        this -> tail->setNext(this -> head);
        this -> head->setPrev(this -> tail);
    }
    // Medio O(n)
    else {
        Node<T>* current = this->searchNode(position);
        toDelete = current;
        current->getPrev()->setNext(current->getNext());
        current->getNext()->setPrev(current->getPrev());
    }
    delete toDelete;
    --this -> length;
}

template<typename T>
bool DoubleCircularList<T>::search(T data) const {
    if (isEmpty()) return false;
    Node<T>* current = this -> head;
    for (int i = 0; i < length; i++) {
        if (current->getData() == data) return true;
        current = current->getNext();
    }
    return false;
}

template<typename T>
Node<T>* DoubleCircularList<T>::searchNode(int position) const {
    if (position < 0 || position >= length) {
        throw std::out_of_range("Posicion invalida");
    }
    Node<T>* current = nullptr;
    if (position < length / 2) {
        current = head;
        for (int i = 0; i < position; i++) current = current->getNext();
    } else {
        current = tail;
        for (int i = length - 1; i > position; i--) current = current->getPrev();
    }
    return current;
}

template<typename T>
T DoubleCircularList<T>::searchPos(int position) const {
    if (position < 0 || position >= length) {
        throw std::out_of_range("Posicion invalida");
    }
    return this->searchNode(position)->getData();
}

template<typename T>
int DoubleCircularList<T>::size() const {
    return length;
}

template<typename T>
bool DoubleCircularList<T>::isEmpty() const {
    return length == 0;
}

template<typename T>
void DoubleCircularList<T>::clear() {
    if (isEmpty()) return;
    tail->setNext(nullptr); // Rompemos  el cicloantes de  eliminar
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
    head = tail = nullptr;
    length = 0;
}

template<typename T>
void DoubleCircularList<T>::print(std::ostream& os) const {
    if (isEmpty()) return;
    Node<T>* current = head;
    for (int i = 0; i < length; i++) {
        os << *current;
        if (i < length - 1) os << "<->";
        current = current->getNext();
    }
    os << "->(" << head->getData() << ")\n";
}

template<typename T>
std::string DoubleCircularList<T>::toDot() const {
    std::ostringstream os;
    os << "digraph {\n";
    os << "  rankdir=LR;\n";
    os << "  node [shape=record];\n";
    if (!isEmpty()) {
        Node<T>* current = head;
        for (int i = 0; i < length; i++) {
            os << "  " << current->getData() << " [label=\"{<prev>|" << current->getData() << "|<next>}\"];\n";
            current = current->getNext();
        }
        current = head;
        for (int i = 0; i < length; i++) {
            Node<T>* next = current->getNext();
            os << "  " << current->getData() << ":next -> " << next->getData() << ":prev;\n";
            os << "  " << next->getData() << ":prev -> " << current->getData() << ":next;\n";
            current = next;
        }
    }
    os << "}\n";
    return os.str();
}

template<typename T>
DoubleCircularList<T>& DoubleCircularList<T>::operator=(DoubleCircularList<T> const& other) {
    if (this == &other) return *this;
    this->clear();
    Node<T>* current = other.head;
    for (int i = 0; i < other.length; i++) {
        insert(current->getData(), length);
        current = current->getNext();
    }
    return *this;
}

template<typename T>
template<typename U>
DoubleCircularList<T>& DoubleCircularList<T>::operator=(DoubleCircularList<U> const& other) {
    if (reinterpret_cast<const void*>(this) == reinterpret_cast<const void*>(&other)) return *this;
    this->clear();
    Node<U>* current = other.head;
    for (int i = 0; i < other.length; i++) {
        insert(static_cast<T>(current->getData()), length);
        current = current->getNext();
    }
    return *this;
}











