//
// Created by DIEGO on 11/04/2026.
//

#ifndef DS_DOUBLE_LINKED_LIST_DOUBLECIRCULARLISTCOMPOSITION_H
#define DS_DOUBLE_LINKED_LIST_DOUBLECIRCULARLISTCOMPOSITION_H
#include "DoubleLinkedList.h"

template<typename T>
class DoubleCircularListComposition {
    private:
        DoubleLinkedList<T> list;
    public:
        void insertFront(T data);      // Insertamos al inicioo
        void insertBack(T data);       // Insertamos al final
        void removeFront();            // Eliminamos al inicio
        void removeBack();             // Eliminamos al final
        void rotate();                 // mover head al siguiente nodo
        [[nodiscard]] T front() const; // ver el primero
        [[nodiscard]] T back() const;  // ver el ultimo
        [[nodiscard]] bool isEmpty() const;
        [[nodiscard]] int size() const;
        [[nodiscard]] std::string toDot() const;

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const DoubleCircularListComposition<U>& list);
};
#include "DoubleCircularListComposition.tpp"
#endif //DS_DOUBLE_LINKED_LIST_DOUBLECIRCULARLISTCOMPOSITION_H