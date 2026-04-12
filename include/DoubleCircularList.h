//
// Created by DIEGO on 11/04/2026.
//

#ifndef DS_DOUBLE_LINKED_LIST_CIRCULARLIST_H
#define DS_DOUBLE_LINKED_LIST_CIRCULARLIST_H

#pragma once
#include "List.h"
#include "Node.h"
#include <ostream>

template<typename T>
class DoubleCircularList: public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;
        template<typename U>
        friend class DoubleCircularList;
    public:
        DoubleCircularList();
        DoubleCircularList(const DoubleCircularList<T>& other);
        template<typename U>
        DoubleCircularList(const DoubleCircularList<U>& other);
        ~DoubleCircularList() override;

        void insert(T data, int position) override;
        void remove(int position) override;
        [[nodiscard]] bool search(T data) const override;
        [[nodiscard]] Node<T>* searchNode(int position) const override;
        [[nodiscard]] int size() const override;
        [[nodiscard]] bool isEmpty() const override;
        void clear() override;
        [[nodiscard]] std::string toDot() const override;
        [[nodiscard]] T searchPos(int position) const;

        DoubleCircularList<T>& operator=(const DoubleCircularList<T>& other);
        template<typename U>
        DoubleCircularList<T>& operator=(const DoubleCircularList<U>& other);

    protected:
        void print(std::ostream& os) const override;

};
#include "DoubleCircularList.tpp"

#endif //DS_DOUBLE_LINKED_LIST_CIRCULARLIST_H










