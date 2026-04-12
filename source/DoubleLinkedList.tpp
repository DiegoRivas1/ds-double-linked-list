//
// Created by DIEGO on 10/04/2026.
//
#pragma once

#include <stdexcept>
#include <iostream>
#include <sstream>

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(): head(nullptr), tail(nullptr),length(0) {}

//Constructor estandar obligatorio
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& other)
    : head(nullptr), tail(nullptr), length(0) {

    *this = other;
}
// Constructor templado de conversion
template<typename T>
template<typename U>
DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList<U> const &other) : head(nullptr), tail(nullptr), length(0) {
    *this = other;
}


template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    this ->DoubleLinkedList<T>::clear();
}

template <typename T>
void DoubleLinkedList<T>::insert(T data, int position) {
    if (position < 0 || position > length) {
        throw std::out_of_range("Posicion invalida");
    }

    auto* newNode = new Node<T>(data);//Node<T>* newNode = new Node<T>(data);

    //Lista vacia O(1)
    if (this -> isEmpty()) {
        this -> head = newNode;
        this -> tail = newNode;
    }

    //Inicio O(1)
    else if (position == 0) {
        newNode -> setNext(this -> head);
        this -> head -> setPrev(newNode);
        this -> head = newNode;
    }
    //Final O(1)
    else if (position == this -> length) {
        this -> tail -> setNext(newNode);
        newNode -> setPrev(this -> tail);
        this ->tail = newNode;
    }

    //Medio O(n)
    else {
        Node<T>* current = this -> searchNode(position - 1);
        newNode -> setNext(current -> getNext());
        newNode -> setPrev(current);
        current -> getNext() -> setPrev(newNode);
        current -> setNext(newNode);
    }
    ++this -> length;
}

template <typename T>
void DoubleLinkedList<T>::remove(int position) {
    if (position < 0 || position >= length) {
        throw std::out_of_range("Posicion invalida");
    }

    Node<T>* toDelete;

    //Unn elemtno O(1)
    if (this -> length == 1) {
        toDelete = this -> head;
        head = nullptr;
        tail = nullptr;
    }
    //Inicio O(1)
    else if (position == 0) {
        toDelete = this -> head;
        this -> head = this -> head -> getNext();
        this -> head ->  setPrev(nullptr);
    }
    //Final O(1)
    else if (position == length - 1) {
        toDelete = this -> tail;
        this -> tail = this -> tail -> getPrev();
        this -> tail -> setNext(nullptr);
    }
    //Medio O(n)
    else {
        Node<T>* current = this -> searchNode(position);
        toDelete = current;
        current -> getPrev() -> setNext(current -> getNext());
        current -> getNext() -> setPrev(current -> getPrev());
    }
    delete toDelete;
    --this -> length;
}

template<typename T>
bool DoubleLinkedList<T>::search(T data) const {
    Node<T>* current = this -> head;
    while (current != nullptr) {
        if (current -> getData() == data) {
            return true;
        }
        current = current -> getNext();
    }
    return false;
}

template<typename T>
T DoubleLinkedList<T>::searchPos(int position) const {
    if (position < 0 || position >= length) {
        throw std::out_of_range("Posicion invalida");
    }
    //BUscamos de los extremos el mas cercano
    Node<T>* current = this -> searchNode(position);
    return current -> getData();
}

template<typename T>
Node<T>* DoubleLinkedList<T>::searchNode(int position) const {
    if (position < 0 || position >= length) {
        throw std::out_of_range("Posicion invalida");
    }
    /* Redundante
    if (position == 0) { //O(1)
        return this -> head -> getData();
    }
    if (position == length - 1) { //O(1)
        return this -> tail -> getData();
    }
    */
    //BUscamos de los extremos el mas cercano
    Node<T>* current = nullptr;
    if (position < this -> length / 2) {
        current = this -> head;
        for (int i = 0; i < position; i++) {
            current = current -> getNext();
        }
    }
    else {
        current = this -> tail;
        for (int i = length - 1; i > position; i--) {
            current = current -> getPrev();
        }
    }
    return current;
}

template<typename T>
int DoubleLinkedList<T>::size() const {
    return this -> length;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() const {
    return this -> length == 0;
}

template<typename T>
void DoubleLinkedList<T>::print(std::ostream &os) const {
    if (isEmpty()) return;
    Node<T>* current = head;
    while (current != nullptr) {
        os << *current;
        if (current->getNext() != nullptr) os << "<->";
        current = current->getNext();
    }
    os << std::endl;
}

template<typename T>
std::string DoubleLinkedList<T>::toDot() const {
    std::ostringstream os;
    os << "digraph {\n";
    os << " rankdir=LR;\n";
    os << " node [shape=record];\n";
    Node<T>* current = this -> head;

    while (current != nullptr) {
        os << " " << current -> getData() << "[label=\"{<prev>|" << current -> getData() << "|<next>}\"];\n";
        if (current -> getNext() != nullptr) {
            os << " " << current -> getData() << ":next -> " << current -> getNext() -> getData() << ":prev;\n";
            os << "  " << current->getNext()->getData() << ":prev -> " << current->getData() << ":next;\n";
        }
        current = current -> getNext();
    }
    os << "}\n";
    return os.str();
}

/*Redundante os << (List<T>&)list; padre ya ace esto
template <typename U>
std::ostream& operator << (std::ostream& os, DoubleLinkedList<U> const& list) {
    list.print(os);
    return os;
}
*/

template<typename T>
void DoubleLinkedList<T>::clear() {
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
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& other) {
    if (this == &other) return *this; // evitar auto-asignación

    // Liberaramos la memoria actual
    this ->clear();

    // Copiamos elementos
    Node<T>* temp = other.head;
    while (temp != nullptr) {
        insert(temp->getData(), length);
        temp = temp->getNext();
    }

    return *this;
}

template<typename T>
template<typename U>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<U>& other) {
    //if (static_cast<void *>(this) == static_cast<void *>(&other)) return *this;
    if (reinterpret_cast<const void*>(this) == reinterpret_cast<const void*>(&other))
        return *this;
    this -> clear();

    Node<U>* current = other.head;
    while (current != nullptr) {
        insert(static_cast<T>(current->getData()), length);
        current = current->getNext();
    }

    return *this;
}