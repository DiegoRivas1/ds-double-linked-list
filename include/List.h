//
// Created by DIEGO on 10/04/2026.
//

#ifndef DS_DOUBLE_LINKED_LIST_LIST_H
#define DS_DOUBLE_LINKED_LIST_LIST_H
#include <iosfwd>
#include "Node.h"

template<typename T>
class List {
    public:
        virtual void insert(T data, int position) = 0;
        virtual void remove(int position) = 0;
        [[nodiscard]] virtual bool search(T data) const = 0;
        [[nodiscard]] virtual Node<T>* searchNode(int position) const = 0;
        [[nodiscard]] virtual int size() const = 0;
        [[nodiscard]] virtual bool isEmpty() const = 0;
        virtual void clear() = 0;
        [[nodiscard]] virtual std::string toDot() const = 0;

        List() = default;
        virtual ~List() = default;

        template<typename U>
        friend std::ostream &operator<<(std::ostream &os, List<U> const &list);
    protected:
        virtual void print(std::ostream& os) const = 0;
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const List<U>& list) {
    list.print(os);
    return os;
}

#endif //DS_DOUBLE_LINKED_LIST_LIST_H