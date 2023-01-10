//
// Created by W0L1D on 1/10/2023.
//

#ifndef ILISI2_C___BINARYTREE2_PAIR_H
#define ILISI2_C___BINARYTREE2_PAIR_H
#include <iostream>

template <typename T, typename U>
class Pair {
public:
    T first;
    U second;

    Pair(T first, U second) : first(first), second(second) { }

    friend std::ostream& operator<<(std::ostream& os, const Pair<T, U>& obj) {
        os << "(" << obj.first << ", " << obj.second << ")";
        return os;
    }

    friend bool operator==(const Pair<T, U> &lhs, const Pair<T, U> &rhs) {
        return lhs.first == rhs.first;
    }

    friend bool operator!=(const Pair<T, U> &lhs, const Pair<T, U> &rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const Pair<T, U> &lhs, const Pair<T, U> &rhs) {
        return lhs.first < rhs.first;
    }
    friend bool operator>(const Pair<T, U> &lhs, const Pair<T, U> &rhs) {
        return lhs.first > rhs.first;
    }
};

template <typename T, typename U>
Pair<T, U> make_pair2(T first, U second) {
    return Pair<T, U>(first, second);
}


#endif //ILISI2_C___BINARYTREE2_PAIR_H
