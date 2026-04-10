//
// Created by DIEGO on 09/04/2026.
//

#ifndef DS_DOUBLE_LINKED_LIST_NODE_H
#define DS_DOUBLE_LINKED_LIST_NODE_H
#include <iosfwd>

template <typename T>
class Node {
    private:
        T data;
        Node<T>* next;
        Node<T>* prev;
    public:
        Node(T data);
        Node(T data, Node<T>* next, Node<T>* prev);
        ~Node();
        [[nodiscard]] T getData() const;
        void setData(T data);
        [[nodiscard]] Node<T>* getNext() const;
        void setNext(Node<T>* next);
        [[nodiscard]] Node<T>* getPrev() const;
        void setPrev(Node<T>* prev);

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Node<U>& node);

};
#include <../source/Node.tpp>
#endif //DS_DOUBLE_LINKED_LIST_NODE_H