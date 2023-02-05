//
// Created by W0L1D on 2/5/2023.
//
#include "HashTable.h"
#include <algorithm>
#include <chrono>

using namespace std;

int main() {
    HashTable<int, std::string> hashTable(10);

    char* buffer = new char[30];

    long max = 10000000;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < max; ++i) {
        sprintf(buffer, "this a string %d", i);
        hashTable.insert(i, buffer);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "L'insertion de "<< max <<" elements a pris " << duration.count() << " ms" <<endl;



    // Providing a seed value
    srand((unsigned) time(NULL));
    for (int i = 0; i < 100; ++i) {
        int random = rand()%max;

        std::cout << "index : " << random << ", found : " <<  hashTable.search(random) << "\n";
    }

//
//    // Insert key-value pairs
//    hashTable.insert(1, "first");
//    hashTable.insert(2, "second");
//    hashTable.insert(3, "third");
//
//
//
//
//
//    // Search for values using keys
//    std::cout << "First value: " << hashTable.search(1) << std::endl;
//    std::cout << "Second value: " << hashTable.search(2) << std::endl;
//    std::cout << "Third value: " << hashTable.search(3) << std::endl;

    return 0;
}