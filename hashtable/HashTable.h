//
// Created by W0L1D on 2/5/2023.
//

#ifndef ILISI2_C___BINARYTREE2_HASHTABLE_H
#define ILISI2_C___BINARYTREE2_HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>



template <typename K, typename V>
class HashTable {
private:
    std::vector<std::list<std::pair<K, V>>> table;
    int size;

public:
    HashTable(int s) : size(s), table(std::vector<std::list<std::pair<K, V>>>(s)) {}

    int hashFunction(K key) {
        return key % size;
    }

    void insert(K key, V value) {
        int index = hashFunction(key);
        table[index].push_back(std::make_pair(key, value));
    }

    V search(K key) {
        int index = hashFunction(key);
        for (const auto &pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return V();
    }
};


#endif //ILISI2_C___BINARYTREE2_HASHTABLE_H
