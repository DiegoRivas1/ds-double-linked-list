//
// Created by DIEGO on 10/04/2026.
//

#ifndef DS_DOUBLE_LINKED_LIST_DOUBLELINKEDLIST_H
#define DS_DOUBLE_LINKED_LIST_DOUBLELINKEDLIST_H

#include "List.h"
#include "Node.h"
#include <ostream>

template<typename T>
class DoubleLinkedList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;
        template <typename U>
        friend class DoubleLinkedList;
    public:
        DoubleLinkedList();
        DoubleLinkedList(DoubleLinkedList<T> const &other);
        template <typename U>
        DoubleLinkedList(DoubleLinkedList<U> const &other);

        ~DoubleLinkedList() override;

        void insert(T data, int position) override;
        void remove(int position) override;
        [[nodiscard]] bool search(T data) const override;
        [[nodiscard]] Node<T>* searchNode(int position) const override;
        [[nodiscard]] int size() const override;
        [[nodiscard]] bool isEmpty() const override;
        void clear() override;
        [[nodiscard]] std::string toDot() const override;
        [[nodiscard]] T searchPos(int position) const;

        //template <typename U>
        //friend std::ostream& operator<<(std::ostream& os, const DoubleLinkedList<U>& list);
        DoubleLinkedList<T>& operator=(DoubleLinkedList<T> const &other);
        template<typename U>
        DoubleLinkedList<T>& operator=(const DoubleLinkedList<U>& other);

    protected:
        void print(std::ostream& os) const override;
};
#include "DoubleLinkedList.tpp"

#endif //DS_DOUBLE_LINKED_LIST_DOUBLELINKEDLIST_H