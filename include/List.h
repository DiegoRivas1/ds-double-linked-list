//
// Created by DIEGO on 10/04/2026.
//

#ifndef DS_DOUBLE_LINKED_LIST_LIST_H
#define DS_DOUBLE_LINKED_LIST_LIST_H
#include <iosfwd>

template<typename T>
class List {
    public:
        virtual void insert(T data, int position) = 0;
        virtual void remove(int position) = 0;
        [[nodiscard]] virtual bool search(T data) const = 0;
        [[nodiscard]] virtual int size() const = 0;
        [[nodiscard]] virtual bool isEmpty() const = 0;
        virtual void print() const = 0;
        [[nodiscard]] virtual std::string toDot() const = 0;

        List() = default;
        virtual ~List() = default;

        template<typename U>
        friend std::ostream &operator<<(std::ostream &os, List<U> const &list);
};

#endif //DS_DOUBLE_LINKED_LIST_LIST_H