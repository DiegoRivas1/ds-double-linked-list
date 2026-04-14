//#pragma once
#pragma once
#include <stdexcept>
#include <sstream>
#include <iostream>
#include "DoubleCircularListComposition.h"

template<typename T>
void DoubleCircularListComposition<T>::insertFront(T data) {
    list.insert(data, 0);
}

template<typename T>
void DoubleCircularListComposition<T>::insertBack(T data) {
    list.insert(data, list.size());
}

template<typename T>
void DoubleCircularListComposition<T>::removeFront() {
    if (isEmpty()) throw std::out_of_range("Lista vacia");
    list.remove(0);
}

template<typename T>
void DoubleCircularListComposition<T>::removeBack() {
    if (isEmpty()) throw std::out_of_range("Lista vacia");
    list.remove(list.size() - 1);
}

template<typename T>
void DoubleCircularListComposition<T>::rotate() {
    if (isEmpty()) throw std::out_of_range("Lista vacia");
    // tomamos el frente, lo quitamos y lo insertamos al final
    T data = list.searchPos(0);
    list.remove(0);
    list.insert(data, list.size());
}

template<typename T>
T DoubleCircularListComposition<T>::front() const {
    if (isEmpty()) throw std::out_of_range("Lista vacia");
    return list.searchPos(0);
}

template<typename T>
T DoubleCircularListComposition<T>::back() const {
    if (isEmpty()) throw std::out_of_range("Lista vacia");
    return list.searchPos(list.size() - 1);
}

template<typename T>
bool DoubleCircularListComposition<T>::isEmpty() const {
    return list.isEmpty();
}

template<typename T>
int DoubleCircularListComposition<T>::size() const {
    return list.size();
}

template<typename T>
std::string DoubleCircularListComposition<T>::toDot() const {
    if (list.isEmpty()) return "digraph DoubleCircularListComposition {}\n";
    std::string dot = list.toDot();
    dot.erase(dot.size() - 2); // quitar "}\n"
    // agregar ciclo
    std::ostringstream cycle;
    cycle << "  node" << list.size()-1 << ":next -> node0:w [tailclip=false, color=\"#27AE60\", style=dashed];\n";
    cycle << "  node0:prev -> node" << list.size()-1 << ":e [tailclip=false, color=\"#27AE60\", style=dashed];\n";
    cycle << "}\n";
    dot += cycle.str();
    return dot;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const DoubleCircularListComposition<U>& c) {
    if (c.isEmpty()) return os;
    std::ostringstream temp;
    temp << c.list;
    std::ostringstream cycle;
    cycle << "->(" << c.front() << ")";
    std::string str = temp.str();
    str.insert(str.size() - 1, cycle.str()); // insertar antes del \n
    os << str;
    //"1<->2<->3\n" nos da c.list, pero queremos "1<->2<->3->(1)\n"
    //sino adecuamos el ultimo nodo apuntando al inicio saldria "1<->2<->3\n->(1)\n"
    return os;
}